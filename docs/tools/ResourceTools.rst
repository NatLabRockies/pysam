ResourceTools
==============

Overview
--------

The ResourceTools module provides utilities for downloading, formatting, and working with solar and wind resource data from national databases. These tools streamline the process of obtaining weather data needed for PySAM simulations.

Key features:

- Download solar resource data from the National Solar Radiation Database (NSRDB)
- Download wind resource data from the WIND Toolkit
- Format resource data for use in PySAM models
- Convert between resource file formats and Python dictionaries
- Fetch and parse utility rate data

ResourceTools is included with PySAM. Import it with:

.. code-block:: python

    import PySAM.ResourceTools as tools

Data Sources
------------

National Solar Radiation Database (NSRDB)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The NSRDB provides solar and meteorological data for locations across the Americas. Data includes:

- Global Horizontal Irradiance (GHI)
- Direct Normal Irradiance (DNI)
- Diffuse Horizontal Irradiance (DHI)
- Temperature, wind speed, and other meteorological variables
- Temporal resolution: 30-minute or hourly
- Spatial resolution: 4 km

**Website:** https://nsrdb.nrel.gov/

WIND Toolkit
~~~~~~~~~~~~

The WIND Toolkit provides wind resource data for the continental United States. Data includes:

- Wind speed at multiple heights
- Wind direction
- Temperature and pressure
- Temporal resolution: 5-minute
- Spatial resolution: 2 km

**Website:** https://www.nrel.gov/grid/wind-toolkit.html

API Key
-------

To download resource data from NREL APIs, you need a free API key:

1. Sign up at https://developer.nrel.gov/signup/
2. You'll receive an API key via email
3. Use the key in the ``api_key`` parameter when fetching data

**Rate Limits:** The API allows 1,000 requests per hour per API key.

Relevant Examples
------------------

1. **FetchResourceFileExample.py**

    https://github.com/NREL/pysam/blob/main/Examples/FetchResourceFileExample.py

API Reference
-------------

.. automodule:: files.ResourceTools
    :members:
    :undoc-members: