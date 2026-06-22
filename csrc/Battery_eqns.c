#include "SAM_eqns.h"

char Reopt_size_standalone_battery_post_doc[] =
        "Given a PV system with Utilityrate5 parameters, get the optimal battery size.\n"
        "Maps SAM compute module inputs to those of the ReOpt API:\n"
        "Pvsamv1 model linked with Battery, Utilityrate5, with Cashloan optional.\n\n"
        "For more information on which PySAM variables are used, see: https://github.com/NREL/ssc/blob/develop/ssc/cmod_battery_eqns.h\n\n"
        "For an example, see the 'Examples' readthedocs page.";

static PyObject* Reopt_size_standalone_battery_post(PyObject *self, PyObject *args, PyObject *keywds)
{

    CmodObject* self_obj = (CmodObject*)self;

    SAM_table data = self_obj->data_ptr;

    SAM_error error = new_error();

    PyObject* reopt_post_obj = NULL;
    error = new_error();
    SAM_Reopt_size_standalone_battery_post_eqn(data, &error);

    if (PySAM_has_error(error)){
        return NULL;
    }

    error = new_error();
    SAM_table reopt_post = SAM_table_get_table(data, "reopt_scenario", &error);
    if (PySAM_has_error(error))
        goto cleanup;

    error = new_error();
    const char* log_msg = SAM_table_get_string(data, "log", &error);
    if (PySAM_has_error(error))
        goto cleanup;

    SAM_table results = SAM_table_construct(NULL);
    SAM_table_set_table(results, "reopt_post", reopt_post, NULL);
    SAM_table_set_string(results, "messages", log_msg, NULL);
    reopt_post_obj = PySAM_table_to_dict(results);
    SAM_table_destruct(results, NULL);

    cleanup:
    SAM_table_unassign_entry(data, "reopt_scenario", NULL);
    SAM_table_unassign_entry(data, "log", NULL);
    return reopt_post_obj;
}

char Size_battery_doc[] =
            "Helper function for battery_model_sizing. Modifies Battery model with new sizing. For BatteryStateful use size_batterystateful.\n"
            ":param model: PySAM.Battery model\n"
    ":param float desired_power: Desired battery power, kWAC if AC-connected, kWDC otherwise.\n"
    ":param float desired_capacity: Desired battery capacity,  kWhAC if AC-connected, kWhDC otherwise.\n"
    ":param float desired_voltage: Desired battery voltage, V.\n"
    ":param bool,optional size_by_ac_not_dc: `True` sizes for power and capacity based on AC cpacities, `False` sizes for DC capacities.\n"
    ":param dict module_dict: {capacity (float), surface_area (float)} Battery module specs for scaling surface area.\n"
    "        capacity: float\n"
    "            Capacity of a single battery module in kWhAC if AC-connected or kWhDC if DC-connected.\n"
    "        surface_area: float\n"
    "            Surface area is of single battery module in m^2.\n"
    
    ":returns: Dictionary of of sizing parameters.\n"
    ":rtype: dict\n";

static PyObject* Size_battery(PyObject *self, PyObject *args, PyObject *keywds)
{

    static char *kwlist[] = {"desired_power", "desired_capacity", "desired_voltage", "size_by_ac_not_dc", "module_capacity", "module_surface_area", "tol", "batt_cell_power_discharge_max", "batt_cell_power_charge_max",
                                     "batt_cell_current_discharge_max", "batt_cell_current_charge_max", NULL};

    double desired_power;
    double desired_capacity;
    double desired_voltage;
    int size_by_ac_not_dc = 0;
    double module_capacity = -1.;
    double module_surface_area = -1.;
    double tol = 0.05;
    double batt_cell_power_discharge_max = 0.;
    double batt_cell_power_charge_max = 0.;
    double batt_cell_current_discharge_max = 0.;
    double batt_cell_current_charge_max = 0.;

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "ddd|iddddddd", kwlist,
                                     &desired_power, &desired_capacity, &desired_voltage, &size_by_ac_not_dc,
                                     &module_capacity, &module_surface_area, &tol,
                                     &batt_cell_power_discharge_max, &batt_cell_power_charge_max,
                                     &batt_cell_current_discharge_max, &batt_cell_current_charge_max))
        return NULL;

    CmodObject* self_obj = (CmodObject*)self;

    SAM_table data = self_obj->data_ptr;

    SAM_table_set_num(data, "desired_power", desired_power, NULL);
    SAM_table_set_num(data, "desired_capacity", desired_capacity, NULL);
    SAM_table_set_num(data, "desired_voltage", desired_voltage, NULL);
    SAM_table_set_num(data, "size_by_ac_not_dc", size_by_ac_not_dc, NULL);
    SAM_table_set_num(data, "module_capacity", module_capacity, NULL);
    SAM_table_set_num(data, "module_surface_area", module_surface_area, NULL);
    SAM_table_set_num(data, "tol", tol, NULL);
    SAM_table_set_num(data, "batt_cell_power_discharge_max", batt_cell_power_discharge_max, NULL);
    SAM_table_set_num(data, "batt_cell_power_charge_max", batt_cell_power_charge_max, NULL);
    SAM_table_set_num(data, "batt_cell_current_discharge_max", batt_cell_current_discharge_max, NULL);
    SAM_table_set_num(data, "batt_cell_current_charge_max", batt_cell_current_charge_max, NULL);

    SAM_error error = new_error();

    PyObject* reopt_post_obj = NULL;
    SAM_size_battery(data, &error);

    if (PySAM_has_error(error)){
        return NULL;
    }

    cleanup:
    SAM_table_unassign_entry(data, "desired_power", NULL);
    SAM_table_unassign_entry(data, "desired_capacity", NULL);
    SAM_table_unassign_entry(data, "desired_voltage", NULL);
    SAM_table_unassign_entry(data, "size_by_ac_not_dc", NULL);
    SAM_table_unassign_entry(data, "module_capacity", NULL);
    SAM_table_unassign_entry(data, "module_surface_area", NULL);
    SAM_table_unassign_entry(data, "tol", NULL);
    SAM_table_unassign_entry(data, "batt_cell_power_discharge_max", NULL);
    SAM_table_unassign_entry(data, "batt_cell_power_charge_max", NULL);
    SAM_table_unassign_entry(data, "batt_cell_current_discharge_max", NULL);
    SAM_table_unassign_entry(data, "batt_cell_current_charge_max", NULL);
    return Py_None;
}