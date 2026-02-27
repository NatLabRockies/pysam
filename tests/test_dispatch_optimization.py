import json
from typing import Sequence
from pathlib import Path
import numpy as np
import PySAM.TcsmoltenSalt as tcsms
from time import perf_counter

model = tcsms.new()

with open(Path(__file__).parent / "dispatch_tcsmolten_salt.json", "r") as f:
    model_inputs = json.load(f)

for k, v in model_inputs.items():
    try:
        model.value(k, v)
    except:
        print(k)

model.value("solar_resource_file", str(Path(__file__).parent / "phoenix_az_33.450495_-111.983688_psmv3_60_tmy.csv"))
start_time = perf_counter()
model.execute()
print("Time", perf_counter() - start_time)

dispatch_outputs = [value for value in model.Outputs.__dir__() if "disp" in value]
for dispatch_output in dispatch_outputs:
    value = model.value(dispatch_output)
    if isinstance(value, Sequence):
        print(f"{dispatch_output}: [{np.min(value)}, {np.max(value)}]")
    else:
        print(f"{dispatch_output}: {value}")