SixParSolve: CEC Module Parameter Solver
==========================================

Overview
--------

The California Energy Commission (CEC) Performance Model uses the University of Wisconsin-Madison Solar Energy Laboratory's five-parameter single-diode model with a database of module parameters for modules from the database of eligible photovoltaic modules maintained by the California Energy Commission (CEC) for the California Solar Initiative.

The five-parameter single-diode model calculates a module's current and voltage under a range of solar resource conditions (represented by an I-V curve) using an equivalent electrical circuit whose electrical properties can be determined from a set of five reference parameters. These five parameters, in turn, are determined from standard reference condition data provided by either the module manufacturer or an independent testing laboratory, such as the Arizona State University Photovoltaic Testing Laboratory.

SAM's implementation extends the model to six parameters by adding an adjustment factor (``Adj``) for temperature coefficients, allowing for more accurate modeling of module performance across varying temperature conditions.

The SixParSolver.py script solves for six-parameter single-diode photovoltaic module model parameters using test data from the California Energy Commission (CEC) module database.
This method is based on Pyomo and IPOPT, and is an alternative to the SSC-based :doc:`/modules/SixParsolve` PySAM module.

**Key Differences:**

- **SixParSolve.py**: Python-based solver using Pyomo optimization framework with IPOPT. Suitable for solving a broader set of modules with configurable error tolerance.
- **PySAM.SixParsolve module**: SSC (System Simulation Core) wrapper that calls compiled C++ code. Faster for single module calculations but less flexible for finding solutions.

The script solves for the following six parameters:

1. **a** - Modified ideality factor (diode factor × thermal voltage)
2. **Il** - Light-generated current at reference conditions (A)
3. **Io** - Diode reverse saturation current at reference conditions (A)
4. **Rs** - Series resistance (Ω)
5. **Rsh** - Shunt resistance (Ω)
6. **Adj** - Adjustment factor for temperature coefficient (%)

These parameters are determined by fitting the single-diode equivalent circuit model to standard test condition (STC) measurements:

- Short-circuit current (I_sc)
- Open-circuit voltage (V_oc)
- Maximum power point current (I_mp) and voltage (V_mp)
- Temperature coefficients (alpha_sc, beta_oc, gamma_r)

Parameter Fit Solutions
-----------------------

The CEC module list will have some modules whose test data don't neatly fit into the 6-parameter module model. 
The solver may still return a non-exact solution, but the curves will not fit well and should be visually examined. 
In SAM, we'll still provide these approximate fits in the module library provided the error is not too large, 
however the power production will be off. For these modules, the IPOPT solution may differ from the SSC solution.

In a test with 21588 modules, 19,556 were solved by both IPOPT and SSC. 1,448 modules were solved only by IPOPT.
In a test with 22,068 modules, 20,754 were solved by both. The ratio of the power production using the Python script vs SSC solution is shown in the below table:

.. list-table:: Python vs SSC Solution Comparison
   :header-rows: 1
   :widths: 30 30 30

   * - Python/SSC Ratio
     - Count
     - Percent
   * - [0.70, 0.75)
     - 2
     - 0.01
   * - [0.75, 0.80)
     - 0
     - 0.00
   * - [0.80, 0.85)
     - 2
     - 0.01
   * - [0.85, 0.90)
     - 16
     - 0.08
   * - [0.90, 0.95)
     - 251
     - 1.21
   * - [0.95, 1.00)
     - 16,570
     - 79.84
   * - [1.00, 1.05)
     - 3,380
     - 16.29
   * - [1.05, 1.10)
     - 515
     - 2.48
   * - [1.10, 1.15)
     - 16
     - 0.08
   * - [1.15, 1.20)
     - 2
     - 0.01
   * - ≥1.20
     - 0
     - 0.00
   * - **All**
     - **20,754**
     - **100.00**

The majority of modules (79.84%) have a ratio between 0.95 and 1.00, indicating the Python solver typically produces slightly lower power predictions than the SSC solver. 
Nearly all modules (96.13%) fall within a 0.95-1.05 ratio range.

Requirements
------------

Python Dependencies
~~~~~~~~~~~~~~~~~~~

::

    pyomo >= 6.0
    pandas
    numpy
    matplotlib
    openpyxl  # For Excel file reading

External Solver - IPOPT
~~~~~~~~~~~~~~~~~~~~~~~

**IPOPT** (Interior Point OPTimizer) is required for nonlinear optimization. There are two installation options:

Option 1: Standard Build (conda-forge)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The conda-forge repository provides a standard build of IPOPT that works well for most use cases:

.. code-block:: bash

    conda install -c conda-forge ipopt

Option 2: High-Performance Build (Custom or IDAES)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For better performance, use an IPOPT build that uses custom linear solvers. The documentation for installing third party linear solvers can be found at the IPOPT website: https://coin-or.github.io/Ipopt/INSTALL.html

The Institute for the Design of Advanced Energy Systems (IDAES) distributes optimized IPOPT binaries compiled with HSL linear solvers.

**Download from:** https://github.com/IDAES/idaes-ext/releases

Choose the appropriate file for your platform:

- **Windows**: ``idaes-solvers-windows-x86_64.tar.gz``
- **Linux**: ``idaes-solvers-ubuntu2004-x86_64.tar.gz`` (or other Linux variants)
- **macOS**: ``idaes-solvers-darwin-x86_64.tar.gz`` or ``idaes-solvers-darwin-aarch64.tar.gz`` (Apple Silicon)

Installation Instructions
"""""""""""""""""""""""""

**Windows:**

1. Download and extract the appropriate ``.tar.gz`` file
2. Locate the ipopt binaries in the extracted files
3. Find your Python environment's ``Scripts`` directory:

   .. code-block::

       python -c "import sys; import os; print(os.path.join(sys.prefix, 'Scripts'))"

4. Copy ``ipopt.exe`` and any required DLL files to the ``Scripts`` directory
5. Verify installation:

   .. code-block:: 

       ipopt -v

**Unix (Linux/macOS):**

1. Download and extract the appropriate ``.tar.gz`` file
2. Locate the ipopt binaries in the extracted files
3. Find your Python environment's ``bin`` directory:

   .. code-block:: bash

       python -c "import sys; import os; print(os.path.join(sys.prefix, 'bin'))"

4. Or, to make IPOPT broadly available instead, create a symlink to the ``ipopt`` binary:

   .. code-block:: bash

       ln -s /path/to/extracted/ipopt $(python -c "import sys; import os; print(os.path.join(sys.prefix, 'bin'))")/ipopt

5. Verify installation:

   .. code-block:: bash

       ipopt -v

Usage
-----

Basic Usage
~~~~~~~~~~~

.. code-block:: bash

    python SixParSolve.py path/to/PV_Module_List_Full_Data_ADA.xlsx

The script expects an Excel file containing CEC module data downloaded from:
https://solarequipment.energy.ca.gov/Home/PVModuleList

Output
~~~~~~

The script generates a CSV file: ``cec_modules_params_YYYY-MM-DD.csv``

Output includes:

- All input test data columns
- Solved model parameters: ``a_py``, ``Il_py``, ``Io_py``, ``Rs_py``, ``Rsh_py``, ``Adj_py``
- IV curve differences: ``d_Isc``, ``d_Imp``, ``d_Vmp``, ``d_Pmp`` (normalized errors)
- ``Error`` column indicating any solution failures

Configuration
-------------

There are various configuration parameters used in the script:

.. code-block:: python

    plotting=False                  # Enable IV curve plotting
    run_parallel=True               # Enable parallel processing
    num_workers=8                   # Parallel processing workers
    il_scaling=1e8                  # Scaling factor for Io parameter
    rsh_scaling=1e-3                # Scaling factor for Rsh parameter
    gamma_curve_dt=3                # Temperature interval for gamma fitting (K)
    reduced_gamma_curve_dt=15       # An increased interval for a looser fit (K)
    max_iter=3000                   # Maximum IPOPT iterations
    tolerance=1e-9                  # Solver tolerance
    infeasibility_threshold_max=0.5 # Maximum normalized error threshold
    infeasibility_threshold_sum=0.5 # Sum of normalized errors threshold

Solution Strategy
-----------------

The script uses a three-pass solving approach to maximize success rate:

Pass 1: Empirical Initial Guess
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Uses empirical relationships derived from previously-solved modules
- Initial guesses based on test data (V_oc, V_mp, I_sc, I_mp)

Pass 2: Bootstrapping from Similar Modules
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- For unsolved modules, finds the closest solved module in parameter space
- Uses that solution as initial guess

Pass 3: Reduced Temperature Sampling
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- For remaining unsolved modules
- Reduces temperature sampling interval to 15K (from 3K)
- Fewer constraints allow more modules to converge
- Slight reduction in accuracy for gamma_r fitting

Optional: Approximate Solutions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The ``solve_bootstrapping_reduced_approx()`` function can provide approximate solutions when exact convergence fails, using the ``solve_model_best_solution()`` approach. **Use with caution** - visual inspection of IV curves is recommended.

Validation
----------

Solutions are validated using normalized errors between model predictions and test data:

- ``d_Isc`` - Error in short-circuit current
- ``d_Imp`` - Error in maximum power point current
- ``d_Vmp`` - Error in maximum power point voltage
- ``d_Pmp`` - Error in maximum power

Solutions with ``max(|errors|) > infeasibility_threshold_max`` or ``sum(|errors|) > infeasibility_threshold_sum`` are marked as infeasible.

Plotting IV Curves
------------------

This generates IV curve plots for each module showing:

- Model-predicted curves at multiple irradiance and temperature conditions
- Reference points (I_sc, V_oc, maximum power point) as markers
- Comparison between initial guess and final solution

Plots are saved to ``6parsolve_output/IV_curve_<index>.png``

Troubleshooting
---------------

Solutions Not Converging
~~~~~~~~~~~~~~~~~~~~~~~~~

1. Check input data for NaN or invalid values
2. Verify V_oc > V_mp (physical constraint)
3. Adjust ``il_scaling`` and ``rsh_scaling`` if solution struggles
4. Try reducing ``gamma_curve_dt`` to 15 for difficult modules (less accurate gamma fitting)
5. Use bootstrapping approach with previously-solved modules
6. Consider relaxing ``infeasibility_threshold_max`` threshold for exploratory analysis

Poorly-fit IV Curves
~~~~~~~~~~~~~~~~~~~~

Check test data quality from CEC database as quite a few modules may have inconsistent manufacturer data, 
or data that doesn't neatly fit into the 6-parameter module model. 

API Reference
-------------

.. automodule:: files.SixParSolve
    :members:
    :undoc-members: