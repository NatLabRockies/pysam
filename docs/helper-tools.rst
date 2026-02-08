Helper Functions (Tools)
=========================

PySAM includes several helper tools that provide additional functionality beyond the core simulation models. 
These tools assist with data preparation, resource file handling, battery modeling, utility rate calculations, and photovoltaic module parameter fitting.

The tools covered in this section include:

- **Resource Tools**: Download and format solar and wind resource data from national databases
- **Battery Tools**: Utilities for battery system modeling and analysis
- **Load Tools**: Manipulate and analyze electrical load profiles
- **Utility Rate Tools**: Convert utility rate data from URDB to SAM format
- **CEC Module Parameter Solver**: Fit six-parameter single-diode model to photovoltaic module test data

.. toctree::
    :maxdepth: 1

    tools/ResourceTools
    tools/BatteryTools
    tools/LoadTools
    tools/UtilityRateTools
    tools/SixParSolve