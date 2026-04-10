PySAM Overview
==========================================

PySAM is a Python package for the National Laboratory of the Rockies' `System Advisor Model (SAM) <https://sam.nlr.gov>`_. It is part of the `SAM Software Development Kit (SDK) <https://sam.nlr.gov/software-development-kit>`_, which provides tools for developers who write code that interacts with the SAM Simulation Core (SSC) application programming interface (API).

SSC, SAM, and PySAM are NLR open source code projects hosted on GitHub.com.

`SSC <https://github.com/natlabrockies/ssc>`_ is a library of performance and financial "compute modules" for modeling renewable energy projects. The SSC API is defined in the C header file, `sscapi.h <https://github.com/natlabrockies/ssc/blob/develop/ssc/sscapi.h>`_.

`SAM <https://github.com/natlabrockies/sam>`_ is a desktop application with a graphical user interface that provides user access to the SSC inputs and outputs, manages SSC inputs, and provides additional functions for modeling tasks such as sizing system components, calculating SSC inputs from user interface inputs, and parametric and stochastic simulations.

`PySAM <https://github.com/natlabrockies/pysam>`_ is a Python package built on the PySSC wrapper for SSC. PySAM provides access to SSC inputs and outputs with some additional functions for building renewable energy models in Python.

The PySAM GitHub repository includes `code examples <https://github.com/natlabrockies/pysam/tree/main/Examples>`_ of some common tasks.

.. important::

    SAM's user interface performs internal calculations to size system components, calculate values for SSC inputs, and other functions that are either not part of SSC or are integrated into the SSC compute modules in a way that is not transparent. Before you create a model in PySAM, create it in SAM and run test simulations to verify that the model works as you expect. Then set it up in PySAM and compare results with SAM. See xxxGotcha for more details.

Recordings of `NREL webinars on PySAM <https://sam.nlr.gov/pysam>`_ are available on the SAM website, along with more information and documentation about SAM.

For help with PySAM, please use the `SAM SDK and PySAM forum <https://sam.nlr.gov/forum/forum-sdk.html>`_. If you are an NREL researcher getting started using PySAM, please `contact SAM Support for guidance <mailto:sam.support@nlr.gov?subject='PySAM%20Support'>`_.
