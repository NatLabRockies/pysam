UtilityRateTools
================

Overview
--------

The UtilityRateTools module provides utilities for converting utility rate data from the Utility Rate Database (URDB) into the format required by SAM's utility rate models. These tools simplify the process of incorporating real-world utility rates into PySAM simulations.

Key features:

- Convert URDB v7 and v8 rate structures to SAM format
- Parse complex rate structures with multiple pricing tiers
- Handle time-of-use (TOU) rates and demand charges
- Support for net metering and export rates
- Simplify rate structure configuration for financial analysis

UtilityRateTools is included with PySAM. Import it with:

.. code-block:: python

    import PySAM.UtilityRateTools as urdb

Utility Rate Database (URDB)
-----------------------------

The Utility Rate Database (URDB) is a comprehensive database of utility rate structures maintained by NREL. It includes:

- Over 6,000 utility rates
- Residential, commercial, and industrial rates
- Time-of-use schedules
- Demand charges
- Tiered energy rates
- Net metering policies

**Access:** https://openei.org/wiki/Utility_Rate_Database

Relevant Examples
------------------

1. **UtilityRatesExample** 

    https://github.com/NREL/pysam/blob/main/Examples/UtilityRatesExample.py

API Reference
-------------

.. automodule:: files.UtilityRateTools
    :members:
    :undoc-members:
