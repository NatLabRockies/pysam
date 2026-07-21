# PySAM Package

https://nlr-pysam.readthedocs.io

* Provides a wrapper around the SAM library that groups together the C API functions by technology or financial model into modules.
* Includes error-checking, explicit input and output definition, and conversion between Python data types.
* PySAM modules are compatible with PySSC, which is included as a subpackage. PySSC is the original wrapper used by SAM's code generator.
* Automatically assign default values to input parameters from SAM's default value database.
* Built-in documentation of models and parameters.


## Requirements
1. Python 3.9 - 3.14, 64 bit
2. Operating system:
	- MacOSX 12.0+
	- Most Linux
	- Windows 10, x64
3. CMake 3.20+


## Installing
1. PyPi:
	```
	pip install nlr-pysam
	```

2. Anaconda (Versions > 1.2.1, < 6.0.0 only):
	```
	conda install -c nlr nlr-pysam
	```

May not be compatible with different builds of the CPython reference interpreter, and not with alternative interpreters such as PyPy, IronPython or Jython

## Usage Examples
- [Examples](https://github.com/NatLabRockies/pysam/tree/main/Examples)


## Citing this package

PySAM <Version>. National Laboratory of the Rockies. Golden, CO. Accessed <date>. https://github.com/NatLabRockies/pysam
