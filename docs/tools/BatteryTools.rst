BatteryTools
=============

Overview
--------

The BatteryTools module provides utilities for battery energy storage system modeling and analysis in PySAM. These tools help with battery sizing, dispatch strategy configuration, and performance analysis.

Key features:

- Battery sizing calculations
- Dispatch strategy helpers
- Battery lifetime and degradation analysis
- Utility functions for battery model configuration
- Integration with PySAM battery-enabled models (PVBattery, StandAloneBattery, etc.)

BatteryTools is included with PySAM. Import it with:

.. code-block:: python

    import PySAM.BatteryTools as battery

Relevant Examples
------------------

1. **Battery Stateful Example**

   https://github.com/NatLabRockies/pysam/blob/main/Examples/PySAMWorkshop.ipynb

2. **Battery Stateful with Custom Life Model Example**

   https://github.com/NatLabRockies/pysam/blob/main/Examples/BatteryStateful_CustomLifeModel.ipynb

API Reference
-------------

.. automodule:: files.BatteryTools
    :members:
    :undoc-members: