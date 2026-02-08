LoadTools
==========

Overview
--------

The LoadTools module provides utilities for manipulating and analyzing electrical load profile data. These tools help prepare load data for PySAM simulations, particularly for utility rate analysis and demand charge calculations.

Key features:

- Load profile manipulation and scaling
- Peak demand identification (monthly, annual)
- Time-of-use period assignment
- Load profile generation and synthesis
- Integration with utility rate structures

LoadTools is included with PySAM. Import it with:

.. code-block:: python

    import PySAM.LoadTools as load

Relevant Examples
------------------

1. **LoadTools Example** 

    https://github.com/NREL/pysam/blob/main/Examples/LoadToolsExample.py

API Reference
-------------

.. automodule:: files.LoadTools
    :members:
    :undoc-members: