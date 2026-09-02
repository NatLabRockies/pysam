Helper Functions (Tools)
=========================

These helper functions provide additional functionality for working with specific models.

Resource Tools
---------------

Access resource tools with ``import PySAM.ResourceTools``.

These functions help with solar resource, wind resource and utility rate data, downloads and formatting.
See how to download solar resource data from the National Solar Radiation Database or wind resource data from the WindToolKit.
Use resource files directly in your PySAM models or input them as dictionaries.

Please see an example of FetchResource: `FetchResourceFileExample.py <https://github.com/natlabrockies/pysam/blob/main/Examples/FetchResourceFileExample.py>`_

.. automodule:: PySAM.ResourceTools
    :members:
    :undoc-members:

Battery Tools
---------------

Access battery tools with ``import PySAM.BatteryTools``.

.. automodule:: PySAM.BatteryTools
    :members:
    :undoc-members:

Load Tools
---------------

Access load tools with ``import PySAM.LoadTools``.

These functions help manipulate load data for local analysis and the utility rate functions

Please see an example of get_monthly_peaks: `LoadToolsExample.py <https://github.com/natlabrockies/pysam/blob/main/Examples/LoadToolsExample.py>`_

.. automodule:: PySAM.LoadTools
    :members:
    :undoc-members:

Utility Rate Tools
------------------

Access utility rate tools with ``import PySAM.UtilityRateTools``.

These functions translate URDB data into the SAM format

Please see an example of URDBv8_to_ElectricityRates `here <https://github.com/natlabrockies/pysam/blob/main/Examples/UtilityRatesExample.py>`_

.. automodule:: PySAM.UtilityRateTools
    :members:
    :undoc-members:

Pvsamv1 Tools
-------------

Access Pvsamv1 tools with ``import PySAM.Pvsamv1Tools``.

These functions are for PV system design and layout

For examples, see `here <https://github.com/NatLabRockies/pysam/blob/main/Examples/PVsamv1Tools.ipynb>`_

.. automodule:: PySAM.Pvsamv1Tools
    :members:
    :undoc-members:

