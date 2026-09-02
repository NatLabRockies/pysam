import json
import subprocess
import sys

import pytest

# The measurement loop runs in a subprocess: ru_maxrss is the process-lifetime PEAK RSS,
# so measuring in the pytest process would be masked by whichever heavyweight tests ran
# first. A fresh process gives a clean high-water mark regardless of suite order.
_LEAK_LOOP = """
import gc, json, resource, sys
import PySAM.Pvwattsv8 as pv

def max_rss_mb():
    # ru_maxrss is bytes on macOS, kilobytes on Linux
    divisor = 1e6 if sys.platform == "darwin" else 1e3
    return resource.getrusage(resource.RUSAGE_SELF).ru_maxrss / divisor

hourly = [0.0] * 8760
data = {
    "lat": 33.45, "lon": -111.98, "tz": -7.0, "elev": 358.0,
    **{k: hourly for k in ("year", "month", "day", "hour", "minute",
                           "dn", "df", "gh", "wspd", "tdry")},
}

# Warm up allocator high-water mark before measuring
for _ in range(5):
    m = pv.new()
    m.SolarResource.solar_resource_data = data
gc.collect()
before = max_rss_mb()

for _ in range(100):
    m = pv.new()
    m.SolarResource.solar_resource_data = data
gc.collect()

print(json.dumps({"growth_mb": max_rss_mb() - before}))
"""


@pytest.mark.skipif(sys.platform.startswith("win"), reason="resource module is POSIX-only")
def test_table_setter_does_not_leak():
    """Assigning a dict to a table variable must not leak the converted table.

    Regression test for PySAM_table_setter leaking the intermediate SAM_table
    on the success path: ~0.7MB of weather data leaked per solar_resource_data
    assignment, which OOMs long-running services that create a model per request.
    """
    # -I (isolated mode) keeps the repo-root PySAM/ data dir off sys.path so the
    # installed package is imported regardless of the pytest working directory.
    result = subprocess.run(
        [sys.executable, "-I", "-c", _LEAK_LOOP], capture_output=True, text=True
    )
    assert result.returncode == 0, f"leak-loop subprocess failed: {result.stderr}"
    growth = json.loads(result.stdout.strip().splitlines()[-1])["growth_mb"]

    # The unpatched leak grows peak RSS by ~70MB here; allow generous allocator noise
    assert growth < 20, f"peak RSS grew {growth:.1f} MB over 100 table assignments"
