#include <Python.h>

#include <SAM_MhkCosts.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * MHKCosts Group
 */ 

static PyTypeObject MHKCosts_Type;

static PyObject *
MHKCosts_new(SAM_MhkCosts data_ptr)
{
	PyObject* new_obj = MHKCosts_Type.tp_alloc(&MHKCosts_Type,0);

	VarGroupObject* MHKCosts_obj = (VarGroupObject*)new_obj;

	MHKCosts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* MHKCosts methods */

static PyObject *
MHKCosts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkCosts", "MHKCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MHKCosts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &MHKCosts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MhkCosts", "MHKCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MHKCosts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &MHKCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef MHKCosts_methods[] = {
		{"assign",            (PyCFunction)MHKCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``MHKCosts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)MHKCosts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``MHKCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)MHKCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MHKCosts_get_assembly_and_install_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_assembly_and_install_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_assembly_and_install_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_assembly_and_install_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_assembly_and_install_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_assembly_and_install_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_assembly_and_install_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_assembly_and_install_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_assembly_and_install_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_assembly_and_install_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_assembly_and_install_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_assembly_and_install_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_assembly_and_install_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_assembly_and_install_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_assembly_and_install_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_assembly_and_install_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_development_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_development_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_development_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_development_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_development_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_development_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_development_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_development_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_development_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_development_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_development_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_development_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_development_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_development_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_development_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_development_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_device_rated_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_device_rated_power_nget, self->data_ptr);
}

static int
MHKCosts_set_device_rated_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_device_rated_power_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_devices_per_row(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_devices_per_row_nget, self->data_ptr);
}

static int
MHKCosts_set_devices_per_row(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_devices_per_row_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_elec_infras_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_elec_infras_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_elec_infras_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_elec_infras_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_elec_infras_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_elec_infras_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_elec_infras_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_elec_infras_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_elec_infras_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_elec_infras_cost_modeled_nget, self->data_ptr);
}

static int
MHKCosts_set_elec_infras_cost_modeled(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_elec_infras_cost_modeled_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_elec_infras_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_elec_infras_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_elec_infras_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_elec_infras_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_elec_infras_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_elec_infras_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_elec_infras_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_elec_infras_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_eng_and_mgmt_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_eng_and_mgmt_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_eng_and_mgmt_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_eng_and_mgmt_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_eng_and_mgmt_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_eng_and_mgmt_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_eng_and_mgmt_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_eng_and_mgmt_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_eng_and_mgmt_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_insurance_during_construction_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_insurance_during_construction_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_insurance_during_construction_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_insurance_during_construction_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_insurance_during_construction_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_insurance_during_construction_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_insurance_during_construction_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_insurance_during_construction_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_insurance_during_construction_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_insurance_during_construction_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_insurance_during_construction_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_insurance_during_construction_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_lib_tidal_device(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_MhkCosts_MHKCosts_lib_tidal_device_sget, self->data_ptr);
}

static int
MHKCosts_set_lib_tidal_device(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_MhkCosts_MHKCosts_lib_tidal_device_sset, self->data_ptr);
}

static PyObject *
MHKCosts_get_lib_wave_device(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_MhkCosts_MHKCosts_lib_wave_device_sget, self->data_ptr);
}

static int
MHKCosts_set_lib_wave_device(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_MhkCosts_MHKCosts_lib_wave_device_sset, self->data_ptr);
}

static PyObject *
MHKCosts_get_library_or_input_wec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_library_or_input_wec_nget, self->data_ptr);
}

static int
MHKCosts_set_library_or_input_wec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_library_or_input_wec_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_maintenance_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_maintenance_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_maintenance_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_maintenance_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_maintenance_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_maintenance_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_maintenance_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_maintenance_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_maintenance_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_maintenance_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_maintenance_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_maintenance_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_maintenance_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_maintenance_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_maintenance_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_maintenance_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_marine_energy_tech(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_marine_energy_tech_nget, self->data_ptr);
}

static int
MHKCosts_set_marine_energy_tech(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_marine_energy_tech_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_mooring_found_substruc_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_mooring_found_substruc_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_mooring_found_substruc_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_mooring_found_substruc_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_mooring_found_substruc_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_mooring_found_substruc_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_mooring_found_substruc_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_mooring_found_substruc_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_mooring_found_substruc_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_operations_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_operations_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_operations_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_operations_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_operations_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_operations_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_operations_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_operations_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_operations_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_operations_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_operations_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_operations_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_operations_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_operations_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_operations_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_operations_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_other_financial_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_other_financial_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_other_financial_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_other_financial_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_other_financial_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_other_financial_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_other_financial_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_other_financial_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_other_financial_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_other_financial_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_other_financial_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_other_financial_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_other_infrastructure_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_other_infrastructure_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_other_infrastructure_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_other_infrastructure_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_other_infrastructure_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_other_infrastructure_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_other_infrastructure_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_other_infrastructure_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_other_infrastructure_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_other_infrastructure_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_other_infrastructure_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_other_infrastructure_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_other_infrastructure_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_other_infrastructure_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_other_infrastructure_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_other_infrastructure_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_plant_commissioning_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_plant_commissioning_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_plant_commissioning_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_plant_commissioning_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_plant_commissioning_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_plant_commissioning_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_plant_commissioning_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_plant_commissioning_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_plant_commissioning_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_plant_commissioning_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_plant_commissioning_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_plant_commissioning_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_power_takeoff_system_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_power_takeoff_system_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_power_takeoff_system_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_power_takeoff_system_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_power_takeoff_system_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_power_takeoff_system_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_power_takeoff_system_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_power_takeoff_system_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_power_takeoff_system_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_power_takeoff_system_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_power_takeoff_system_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_power_takeoff_system_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_project_contingency_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_project_contingency_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_project_contingency_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_project_contingency_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_project_contingency_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_project_contingency_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_project_contingency_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_project_contingency_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_project_contingency_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_project_contingency_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_project_contingency_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_project_contingency_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_reserve_accounts_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_reserve_accounts_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_reserve_accounts_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_reserve_accounts_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_reserve_accounts_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_reserve_accounts_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_reserve_accounts_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_reserve_accounts_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_reserve_accounts_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_reserve_accounts_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_reserve_accounts_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_reserve_accounts_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_reserve_accounts_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_reserve_accounts_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_reserve_accounts_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_reserve_accounts_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_site_access_port_staging_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_site_access_port_staging_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_site_access_port_staging_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_site_access_port_staging_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_site_access_port_staging_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_site_access_port_staging_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_site_access_port_staging_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_site_access_port_staging_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_site_access_port_staging_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_structural_assembly_cost_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_structural_assembly_cost_input_nget, self->data_ptr);
}

static int
MHKCosts_set_structural_assembly_cost_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_structural_assembly_cost_input_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_structural_assembly_cost_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_structural_assembly_cost_method_nget, self->data_ptr);
}

static int
MHKCosts_set_structural_assembly_cost_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_structural_assembly_cost_method_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_structural_assembly_cost_rvalue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_structural_assembly_cost_rvalue_nget, self->data_ptr);
}

static int
MHKCosts_set_structural_assembly_cost_rvalue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_structural_assembly_cost_rvalue_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_structural_assembly_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_structural_assembly_cost_total_nget, self->data_ptr);
}

static int
MHKCosts_set_structural_assembly_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_structural_assembly_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKCosts_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_MHKCosts_system_capacity_nget, self->data_ptr);
}

static int
MHKCosts_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkCosts_MHKCosts_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef MHKCosts_getset[] = {
{"assembly_and_install_cost_input", (getter)MHKCosts_get_assembly_and_install_cost_input,(setter)MHKCosts_set_assembly_and_install_cost_input,
	PyDoc_STR("*float*: Assembly and installation cost [$]\n\n**Required:**\nassembly_and_install_cost_method<2"),
 	NULL},
{"assembly_and_install_cost_method", (getter)MHKCosts_get_assembly_and_install_cost_method,(setter)MHKCosts_set_assembly_and_install_cost_method,
	PyDoc_STR("*float*: Assembly and installation cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"assembly_and_install_cost_rvalue", (getter)MHKCosts_get_assembly_and_install_cost_rvalue,(setter)MHKCosts_set_assembly_and_install_cost_rvalue,
	PyDoc_STR("*float*: Assembly and installation R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if assembly_and_install_cost_method=4"),
 	NULL},
{"assembly_and_install_cost_total", (getter)MHKCosts_get_assembly_and_install_cost_total,(setter)MHKCosts_set_assembly_and_install_cost_total,
	PyDoc_STR("*float*: Assembly and installation itemized cost total [$]\n\n**Required:**\nRequired if assembly_and_install_cost_method=3"),
 	NULL},
{"development_cost_input", (getter)MHKCosts_get_development_cost_input,(setter)MHKCosts_set_development_cost_input,
	PyDoc_STR("*float*: Development cost [$]\n\n**Required:**\ndevelopment_cost_method<2"),
 	NULL},
{"development_cost_method", (getter)MHKCosts_get_development_cost_method,(setter)MHKCosts_set_development_cost_method,
	PyDoc_STR("*float*: Development cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value,3=Enter in itemized costs\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"development_cost_rvalue", (getter)MHKCosts_get_development_cost_rvalue,(setter)MHKCosts_set_development_cost_rvalue,
	PyDoc_STR("*float*: Development R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if development_cost_method=4"),
 	NULL},
{"development_cost_total", (getter)MHKCosts_get_development_cost_total,(setter)MHKCosts_set_development_cost_total,
	PyDoc_STR("*float*: Development itemized cost total [$]\n\n**Required:**\nRequired if development_cost_method=3"),
 	NULL},
{"device_rated_power", (getter)MHKCosts_get_device_rated_power,(setter)MHKCosts_set_device_rated_power,
	PyDoc_STR("*float*: Rated capacity of device [kW]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nTrue"),
 	NULL},
{"devices_per_row", (getter)MHKCosts_get_devices_per_row,(setter)MHKCosts_set_devices_per_row,
	PyDoc_STR("*float*: Number of wave devices per row in array\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"elec_infras_cost_input", (getter)MHKCosts_get_elec_infras_cost_input,(setter)MHKCosts_set_elec_infras_cost_input,
	PyDoc_STR("*float*: Electrical infrastructure cost [$]\n\n**Required:**\nelec_infras_cost_method<2"),
 	NULL},
{"elec_infras_cost_method", (getter)MHKCosts_get_elec_infras_cost_method,(setter)MHKCosts_set_elec_infras_cost_method,
	PyDoc_STR("*float*: Electrical infrastructure cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"elec_infras_cost_modeled", (getter)MHKCosts_get_elec_infras_cost_modeled,(setter)MHKCosts_set_elec_infras_cost_modeled,
	PyDoc_STR("*float*: Electrical infrastructure cost modeled [$]\n\n**Required:**\nRequired if elec_infras_cost_method=2"),
 	NULL},
{"elec_infras_cost_rvalue", (getter)MHKCosts_get_elec_infras_cost_rvalue,(setter)MHKCosts_set_elec_infras_cost_rvalue,
	PyDoc_STR("*float*: Electrical infrastructure R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if elec_infras_cost_method=4"),
 	NULL},
{"elec_infras_cost_total", (getter)MHKCosts_get_elec_infras_cost_total,(setter)MHKCosts_set_elec_infras_cost_total,
	PyDoc_STR("*float*: Electrical infrastructure itemized cost total [$]\n\n**Required:**\nRequired if elec_infras_cost_method=3"),
 	NULL},
{"eng_and_mgmt_cost_input", (getter)MHKCosts_get_eng_and_mgmt_cost_input,(setter)MHKCosts_set_eng_and_mgmt_cost_input,
	PyDoc_STR("*float*: Engineering and management cost [$]\n\n**Required:**\neng_and_mgmt_cost_method<2"),
 	NULL},
{"eng_and_mgmt_cost_method", (getter)MHKCosts_get_eng_and_mgmt_cost_method,(setter)MHKCosts_set_eng_and_mgmt_cost_method,
	PyDoc_STR("*float*: Engineering and management cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value,3=Enter in itemized costs\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"eng_and_mgmt_cost_rvalue", (getter)MHKCosts_get_eng_and_mgmt_cost_rvalue,(setter)MHKCosts_set_eng_and_mgmt_cost_rvalue,
	PyDoc_STR("*float*: Engineering and management R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if eng_and_mgmt_cost_method=4"),
 	NULL},
{"eng_and_mgmt_cost_total", (getter)MHKCosts_get_eng_and_mgmt_cost_total,(setter)MHKCosts_set_eng_and_mgmt_cost_total,
	PyDoc_STR("*float*: Engineering and management itemized cost total [$]\n\n**Required:**\nRequired if eng_and_mgmt_cost_method=3"),
 	NULL},
{"insurance_during_construction_cost_input", (getter)MHKCosts_get_insurance_during_construction_cost_input,(setter)MHKCosts_set_insurance_during_construction_cost_input,
	PyDoc_STR("*float*: Insurance during construction cost [$]\n\n**Required:**\ninsurance_during_construction_cost_method<2"),
 	NULL},
{"insurance_during_construction_cost_method", (getter)MHKCosts_get_insurance_during_construction_cost_method,(setter)MHKCosts_set_insurance_during_construction_cost_method,
	PyDoc_STR("*float*: Insurance during construction cost method [0-3]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"insurance_during_construction_cost_rvalue", (getter)MHKCosts_get_insurance_during_construction_cost_rvalue,(setter)MHKCosts_set_insurance_during_construction_cost_rvalue,
	PyDoc_STR("*float*: Insurance during construction R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if insurance_during_construction_cost_method=3"),
 	NULL},
{"lib_tidal_device", (getter)MHKCosts_get_lib_tidal_device,(setter)MHKCosts_set_lib_tidal_device,
	PyDoc_STR("*str*: Tidal library name\n\n**Required:**\nRequired if marine_energy_tech=1"),
 	NULL},
{"lib_wave_device", (getter)MHKCosts_get_lib_wave_device,(setter)MHKCosts_set_lib_wave_device,
	PyDoc_STR("*str*: Wave library name\n\n**Required:**\nRequired if marine_energy_tech=0"),
 	NULL},
{"library_or_input_wec", (getter)MHKCosts_get_library_or_input_wec,(setter)MHKCosts_set_library_or_input_wec,
	PyDoc_STR("*float*: Wave library or user input\n\n**Options:**\n0=Library,1=User\n\n**Required:**\nRequired if marine_energy_tech=0"),
 	NULL},
{"maintenance_cost_input", (getter)MHKCosts_get_maintenance_cost_input,(setter)MHKCosts_set_maintenance_cost_input,
	PyDoc_STR("*float*: Maintenance cost [$]\n\n**Required:**\nmaintenance_cost_method<2"),
 	NULL},
{"maintenance_cost_method", (getter)MHKCosts_get_maintenance_cost_method,(setter)MHKCosts_set_maintenance_cost_method,
	PyDoc_STR("*float*: Maintenance cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"maintenance_cost_rvalue", (getter)MHKCosts_get_maintenance_cost_rvalue,(setter)MHKCosts_set_maintenance_cost_rvalue,
	PyDoc_STR("*float*: Maintenance R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if maintenance_cost_method=4"),
 	NULL},
{"maintenance_cost_total", (getter)MHKCosts_get_maintenance_cost_total,(setter)MHKCosts_set_maintenance_cost_total,
	PyDoc_STR("*float*: Maintenance itemized cost total [$]\n\n**Required:**\nRequired if maintenance_cost_method=3"),
 	NULL},
{"marine_energy_tech", (getter)MHKCosts_get_marine_energy_tech,(setter)MHKCosts_set_marine_energy_tech,
	PyDoc_STR("*float*: Marine energy technology [0/1]\n\n**Options:**\n0=Wave,1=Tidal\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"mooring_found_substruc_cost_input", (getter)MHKCosts_get_mooring_found_substruc_cost_input,(setter)MHKCosts_set_mooring_found_substruc_cost_input,
	PyDoc_STR("*float*: Mooring, foundation, and substructure cost [$]\n\n**Required:**\nmooring_found_substruc_cost_method<2"),
 	NULL},
{"mooring_found_substruc_cost_method", (getter)MHKCosts_get_mooring_found_substruc_cost_method,(setter)MHKCosts_set_mooring_found_substruc_cost_method,
	PyDoc_STR("*float*: Mooring, foundation, and substructure cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value,3=Use itemized costs in $\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"mooring_found_substruc_cost_rvalue", (getter)MHKCosts_get_mooring_found_substruc_cost_rvalue,(setter)MHKCosts_set_mooring_found_substruc_cost_rvalue,
	PyDoc_STR("*float*: Mooring, foundation, and substructure R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if mooring_found_substruc_cost_method=4"),
 	NULL},
{"mooring_found_substruc_cost_total", (getter)MHKCosts_get_mooring_found_substruc_cost_total,(setter)MHKCosts_set_mooring_found_substruc_cost_total,
	PyDoc_STR("*float*: Mooring, foundation, and substructure itemized cost total [$]\n\n**Required:**\nRequired if mooring_found_substruc_cost_method=3"),
 	NULL},
{"operations_cost_input", (getter)MHKCosts_get_operations_cost_input,(setter)MHKCosts_set_operations_cost_input,
	PyDoc_STR("*float*: Operations cost [$]\n\n**Required:**\noperations_cost_method<2"),
 	NULL},
{"operations_cost_method", (getter)MHKCosts_get_operations_cost_method,(setter)MHKCosts_set_operations_cost_method,
	PyDoc_STR("*float*: Operations cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"operations_cost_rvalue", (getter)MHKCosts_get_operations_cost_rvalue,(setter)MHKCosts_set_operations_cost_rvalue,
	PyDoc_STR("*float*: Operations R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if operations_cost_method=4"),
 	NULL},
{"operations_cost_total", (getter)MHKCosts_get_operations_cost_total,(setter)MHKCosts_set_operations_cost_total,
	PyDoc_STR("*float*: Operations itemized cost total [$]\n\n**Required:**\nRequired if operations_cost_method=3"),
 	NULL},
{"other_financial_cost_input", (getter)MHKCosts_get_other_financial_cost_input,(setter)MHKCosts_set_other_financial_cost_input,
	PyDoc_STR("*float*: Other financial cost [$,$/kW]\n\n**Required:**\nother_financial_cost_method<2"),
 	NULL},
{"other_financial_cost_method", (getter)MHKCosts_get_other_financial_cost_method,(setter)MHKCosts_set_other_financial_cost_method,
	PyDoc_STR("*float*: Other financial cost method [0-3]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"other_financial_cost_rvalue", (getter)MHKCosts_get_other_financial_cost_rvalue,(setter)MHKCosts_set_other_financial_cost_rvalue,
	PyDoc_STR("*float*: Other financial R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if other_financial_cost_method=3"),
 	NULL},
{"other_infrastructure_cost_input", (getter)MHKCosts_get_other_infrastructure_cost_input,(setter)MHKCosts_set_other_infrastructure_cost_input,
	PyDoc_STR("*float*: Other infrastructure cost [$]\n\n**Required:**\nother_infrastructure_cost_method<2"),
 	NULL},
{"other_infrastructure_cost_method", (getter)MHKCosts_get_other_infrastructure_cost_method,(setter)MHKCosts_set_other_infrastructure_cost_method,
	PyDoc_STR("*float*: Other infrastructure cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"other_infrastructure_cost_rvalue", (getter)MHKCosts_get_other_infrastructure_cost_rvalue,(setter)MHKCosts_set_other_infrastructure_cost_rvalue,
	PyDoc_STR("*float*: Other infrastructure R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if other_infrastructure_cost_method=4"),
 	NULL},
{"other_infrastructure_cost_total", (getter)MHKCosts_get_other_infrastructure_cost_total,(setter)MHKCosts_set_other_infrastructure_cost_total,
	PyDoc_STR("*float*: Other infrastructure itemized cost total [$]\n\n**Required:**\nRequired if other_infrastructure_cost_method=3"),
 	NULL},
{"plant_commissioning_cost_input", (getter)MHKCosts_get_plant_commissioning_cost_input,(setter)MHKCosts_set_plant_commissioning_cost_input,
	PyDoc_STR("*float*: Plant commissioning cost [$]\n\n**Required:**\nplant_commissioning_cost_method<2"),
 	NULL},
{"plant_commissioning_cost_method", (getter)MHKCosts_get_plant_commissioning_cost_method,(setter)MHKCosts_set_plant_commissioning_cost_method,
	PyDoc_STR("*float*: Plant commissioning cost method [0-3]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"plant_commissioning_cost_rvalue", (getter)MHKCosts_get_plant_commissioning_cost_rvalue,(setter)MHKCosts_set_plant_commissioning_cost_rvalue,
	PyDoc_STR("*float*: Plant commissioning R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if plant_commissioning_cost_method=4"),
 	NULL},
{"power_takeoff_system_cost_input", (getter)MHKCosts_get_power_takeoff_system_cost_input,(setter)MHKCosts_set_power_takeoff_system_cost_input,
	PyDoc_STR("*float*: Power take-off system cost [$]\n\n**Required:**\npower_takeoff_system_cost_method<2"),
 	NULL},
{"power_takeoff_system_cost_method", (getter)MHKCosts_get_power_takeoff_system_cost_method,(setter)MHKCosts_set_power_takeoff_system_cost_method,
	PyDoc_STR("*float*: Power take-off system cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value,3=Use itemized costs in $\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"power_takeoff_system_cost_total", (getter)MHKCosts_get_power_takeoff_system_cost_total,(setter)MHKCosts_set_power_takeoff_system_cost_total,
	PyDoc_STR("*float*: Power take-off system cost itemized cost total [$]\n\n**Required:**\nRequired if power_takeoff_system_cost_method=3"),
 	NULL},
{"project_contingency_cost_input", (getter)MHKCosts_get_project_contingency_cost_input,(setter)MHKCosts_set_project_contingency_cost_input,
	PyDoc_STR("*float*: Project contingency cost [$]\n\n**Required:**\nproject_contingency_cost_method<2"),
 	NULL},
{"project_contingency_cost_method", (getter)MHKCosts_get_project_contingency_cost_method,(setter)MHKCosts_set_project_contingency_cost_method,
	PyDoc_STR("*float*: Project contingency cost method [0-3]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"project_contingency_cost_rvalue", (getter)MHKCosts_get_project_contingency_cost_rvalue,(setter)MHKCosts_set_project_contingency_cost_rvalue,
	PyDoc_STR("*float*: Project contingency R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if project_contingency_cost_method=3"),
 	NULL},
{"reserve_accounts_cost_input", (getter)MHKCosts_get_reserve_accounts_cost_input,(setter)MHKCosts_set_reserve_accounts_cost_input,
	PyDoc_STR("*float*: Reserve accounts cost [$]\n\n**Required:**\nreserve_accounts_cost_method<2"),
 	NULL},
{"reserve_accounts_cost_method", (getter)MHKCosts_get_reserve_accounts_cost_method,(setter)MHKCosts_set_reserve_accounts_cost_method,
	PyDoc_STR("*float*: Reserve accounts cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"reserve_accounts_cost_rvalue", (getter)MHKCosts_get_reserve_accounts_cost_rvalue,(setter)MHKCosts_set_reserve_accounts_cost_rvalue,
	PyDoc_STR("*float*: Reserve accounts R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if reserve_accounts_cost_method=4"),
 	NULL},
{"reserve_accounts_cost_total", (getter)MHKCosts_get_reserve_accounts_cost_total,(setter)MHKCosts_set_reserve_accounts_cost_total,
	PyDoc_STR("*float*: Reserve accounts itemized cost total [$]\n\n**Required:**\nRequired if reserve_accounts_cost_method=3"),
 	NULL},
{"site_access_port_staging_cost_input", (getter)MHKCosts_get_site_access_port_staging_cost_input,(setter)MHKCosts_set_site_access_port_staging_cost_input,
	PyDoc_STR("*float*: Site access and port staging cost [$]\n\n**Required:**\nsite_access_port_staging_cost_method<2"),
 	NULL},
{"site_access_port_staging_cost_method", (getter)MHKCosts_get_site_access_port_staging_cost_method,(setter)MHKCosts_set_site_access_port_staging_cost_method,
	PyDoc_STR("*float*: Site access and port staging cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"site_access_port_staging_cost_rvalue", (getter)MHKCosts_get_site_access_port_staging_cost_rvalue,(setter)MHKCosts_set_site_access_port_staging_cost_rvalue,
	PyDoc_STR("*float*: Site access and port staging R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if site_access_port_staging_cost_method=4"),
 	NULL},
{"site_access_port_staging_cost_total", (getter)MHKCosts_get_site_access_port_staging_cost_total,(setter)MHKCosts_set_site_access_port_staging_cost_total,
	PyDoc_STR("*float*: Site access and port staging itemized cost total [$]\n\n**Required:**\nRequired if site_access_port_staging_cost_method=3"),
 	NULL},
{"structural_assembly_cost_input", (getter)MHKCosts_get_structural_assembly_cost_input,(setter)MHKCosts_set_structural_assembly_cost_input,
	PyDoc_STR("*float*: Structural assembly cost [$]\n\n**Required:**\nstructural_assembly_cost_method<2"),
 	NULL},
{"structural_assembly_cost_method", (getter)MHKCosts_get_structural_assembly_cost_method,(setter)MHKCosts_set_structural_assembly_cost_method,
	PyDoc_STR("*float*: Structural assembly cost method [0-4]\n\n**Options:**\n0=Enter in $/kW,1=Enter in $,2=Use modeled value,3=Use itemized costs in $\n\n**Constraints:**\nMIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"structural_assembly_cost_rvalue", (getter)MHKCosts_get_structural_assembly_cost_rvalue,(setter)MHKCosts_set_structural_assembly_cost_rvalue,
	PyDoc_STR("*float*: Structural assembly R-value\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if structural_assembly_cost_method=4"),
 	NULL},
{"structural_assembly_cost_total", (getter)MHKCosts_get_structural_assembly_cost_total,(setter)MHKCosts_set_structural_assembly_cost_total,
	PyDoc_STR("*float*: Structural assembly itemized cost total [$]\n\n**Required:**\nRequired if structural_assembly_cost_method=3"),
 	NULL},
{"system_capacity", (getter)MHKCosts_get_system_capacity,(setter)MHKCosts_set_system_capacity,
	PyDoc_STR("*float*: System Nameplate Capacity [kW]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject MHKCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkCosts.MHKCosts",             /*tp_name*/
		sizeof(VarGroupObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		MHKCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		MHKCosts_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_MhkCosts data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	VarGroupObject* Outputs_obj = (VarGroupObject*)new_obj;

	Outputs_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkCosts", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Outputs_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MhkCosts", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Outputs_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Outputs_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_assembly_and_install_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_assembly_and_install_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_assembly_and_install_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_assembly_and_install_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_development_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_development_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_development_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_development_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eng_and_mgmt_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_eng_and_mgmt_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eng_and_mgmt_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_eng_and_mgmt_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_insurance_during_construction_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_insurance_during_construction_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_insurance_during_construction_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_insurance_during_construction_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_maintenance_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_maintenance_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_maintenance_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_maintenance_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mooring_found_substruc_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_mooring_found_substruc_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mooring_found_substruc_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_mooring_found_substruc_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_operations_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_operations_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_operations_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_operations_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_other_financial_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_other_financial_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_other_financial_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_other_financial_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_other_infrastructure_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_other_infrastructure_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_other_infrastructure_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_other_infrastructure_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_plant_commissioning_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_plant_commissioning_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_plant_commissioning_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_plant_commissioning_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_power_takeoff_system_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_power_takeoff_system_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_power_takeoff_system_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_power_takeoff_system_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_project_contingency_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_project_contingency_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_project_contingency_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_project_contingency_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_reserve_accounts_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_reserve_accounts_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_reserve_accounts_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_reserve_accounts_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_site_access_port_staging_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_site_access_port_staging_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_site_access_port_staging_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_site_access_port_staging_cost_modeled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_structural_assembly_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_structural_assembly_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_structural_assembly_cost_modeled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkCosts_Outputs_structural_assembly_cost_modeled_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"assembly_and_install_cost", (getter)Outputs_get_assembly_and_install_cost,(setter)0,
	PyDoc_STR("*float*: Assembly and installation cost [$]"),
 	NULL},
{"assembly_and_install_cost_modeled", (getter)Outputs_get_assembly_and_install_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled assembly and installation cost [$]"),
 	NULL},
{"development_cost", (getter)Outputs_get_development_cost,(setter)0,
	PyDoc_STR("*float*: Development cost [$]"),
 	NULL},
{"development_cost_modeled", (getter)Outputs_get_development_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled development cost [$]"),
 	NULL},
{"eng_and_mgmt_cost", (getter)Outputs_get_eng_and_mgmt_cost,(setter)0,
	PyDoc_STR("*float*: Engineering and management cost [$]"),
 	NULL},
{"eng_and_mgmt_cost_modeled", (getter)Outputs_get_eng_and_mgmt_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled engineering and management cost [$]"),
 	NULL},
{"insurance_during_construction_cost", (getter)Outputs_get_insurance_during_construction_cost,(setter)0,
	PyDoc_STR("*float*: Cost of insurance during construction [$]"),
 	NULL},
{"insurance_during_construction_cost_modeled", (getter)Outputs_get_insurance_during_construction_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled cost of insurance during construction [$]"),
 	NULL},
{"maintenance_cost", (getter)Outputs_get_maintenance_cost,(setter)0,
	PyDoc_STR("*float*: Maintenance cost [$]"),
 	NULL},
{"maintenance_cost_modeled", (getter)Outputs_get_maintenance_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled maintenance cost [$]"),
 	NULL},
{"mooring_found_substruc_cost", (getter)Outputs_get_mooring_found_substruc_cost,(setter)0,
	PyDoc_STR("*float*: Mooring, foundation, and substructure cost [$]"),
 	NULL},
{"mooring_found_substruc_cost_modeled", (getter)Outputs_get_mooring_found_substruc_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled mooring, foundation, and substructure cost [$]"),
 	NULL},
{"operations_cost", (getter)Outputs_get_operations_cost,(setter)0,
	PyDoc_STR("*float*: Operations cost [$]"),
 	NULL},
{"operations_cost_modeled", (getter)Outputs_get_operations_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled operations cost [$]"),
 	NULL},
{"other_financial_cost", (getter)Outputs_get_other_financial_cost,(setter)0,
	PyDoc_STR("*float*: Cost of other financial considerations [$]"),
 	NULL},
{"other_financial_cost_modeled", (getter)Outputs_get_other_financial_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled cost of other financial considerations [$]"),
 	NULL},
{"other_infrastructure_cost", (getter)Outputs_get_other_infrastructure_cost,(setter)0,
	PyDoc_STR("*float*: Other infrastructure cost [$]"),
 	NULL},
{"other_infrastructure_cost_modeled", (getter)Outputs_get_other_infrastructure_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled other infrastructure cost [$]"),
 	NULL},
{"plant_commissioning_cost", (getter)Outputs_get_plant_commissioning_cost,(setter)0,
	PyDoc_STR("*float*: Plant commissioning cost [$]"),
 	NULL},
{"plant_commissioning_cost_modeled", (getter)Outputs_get_plant_commissioning_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled plant commissioning cost [$]"),
 	NULL},
{"power_takeoff_system_cost", (getter)Outputs_get_power_takeoff_system_cost,(setter)0,
	PyDoc_STR("*float*: Power take-off cost [$]"),
 	NULL},
{"power_takeoff_system_cost_modeled", (getter)Outputs_get_power_takeoff_system_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled power take-off cost [$]"),
 	NULL},
{"project_contingency_cost", (getter)Outputs_get_project_contingency_cost,(setter)0,
	PyDoc_STR("*float*: Project contingency cost [$]"),
 	NULL},
{"project_contingency_cost_modeled", (getter)Outputs_get_project_contingency_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled project contingency cost [$]"),
 	NULL},
{"reserve_accounts_cost", (getter)Outputs_get_reserve_accounts_cost,(setter)0,
	PyDoc_STR("*float*: Reserve account costs [$]"),
 	NULL},
{"reserve_accounts_cost_modeled", (getter)Outputs_get_reserve_accounts_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled reserve account costs [$]"),
 	NULL},
{"site_access_port_staging_cost", (getter)Outputs_get_site_access_port_staging_cost,(setter)0,
	PyDoc_STR("*float*: Site access, port, and staging cost [$]"),
 	NULL},
{"site_access_port_staging_cost_modeled", (getter)Outputs_get_site_access_port_staging_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled site access, port, and staging cost [$]"),
 	NULL},
{"structural_assembly_cost", (getter)Outputs_get_structural_assembly_cost,(setter)0,
	PyDoc_STR("*float*: Structural assembly cost [$]"),
 	NULL},
{"structural_assembly_cost_modeled", (getter)Outputs_get_structural_assembly_cost_modeled,(setter)0,
	PyDoc_STR("*float*: Modeled structural assembly cost [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkCosts.Outputs",             /*tp_name*/
		sizeof(VarGroupObject),          /*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		0,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		0,                          /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		0,                          /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		0,                          /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * MhkCosts
 */

static PyTypeObject MhkCosts_Type;

static CmodObject *
newMhkCostsObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &MhkCosts_Type);

	PySAM_TECH_ATTR()

	PyObject* MHKCosts_obj = MHKCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "MHKCosts", MHKCosts_obj);
	Py_DECREF(MHKCosts_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* MhkCosts methods */

static void
MhkCosts_dealloc(CmodObject *self)
{
	Py_XDECREF(self->x_attr);

	if (!self->data_owner_ptr) {
		SAM_error error = new_error();
		SAM_table_destruct(self->data_ptr, &error);
		PySAM_has_error(error);
	}
	PyObject_Del(self);
}


static PyObject *
MhkCosts_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
MhkCosts_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_MhkCosts_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
MhkCosts_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MhkCosts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MhkCosts_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MhkCosts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MhkCosts_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
MhkCosts_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
MhkCosts_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef MhkCosts_methods[] = {
		{"execute",           (PyCFunction)MhkCosts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)MhkCosts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'MHKCosts': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)MhkCosts_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'MHKCosts': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)MhkCosts_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)MhkCosts_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)MhkCosts_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)MhkCosts_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MhkCosts_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
MhkCosts_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject MhkCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkCosts",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)MhkCosts_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)MhkCosts_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)MhkCosts_getattro, /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		"This class contains all the variable information for running a simulation. Variables are grouped together in the subclasses as properties. If property assignments are the wrong type, an error is thrown.",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		MhkCosts_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,                          /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/* --------------------------------------------------------------------- */


/* Function of no arguments returning new MhkCosts object */

static PyObject *
MhkCosts_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newMhkCostsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkCosts_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkCostsObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkCosts_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkCostsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MhkCosts", def) < 0) {
		MhkCosts_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
MhkCosts_from_existing(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	PyObject * module = 0;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "O|s:from_existing", &module, &def)){
		PyErr_BadArgument();
		return NULL;
	}
	CmodObject *module_obj = (CmodObject *)module;
	SAM_table ptr = module_obj->data_ptr;

	// do a rough validity check on the data by checking its size
	SAM_error error = new_error();
	int data_size = SAM_table_size(ptr, &error);
	if (PySAM_has_error(error))
		goto fail;
	if (data_size < 0)
		goto fail;

	rv = newMhkCostsObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MhkCosts", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef MhkCostsModule_methods[] = {
		{"new",             MhkCosts_new,         METH_VARARGS,
				PyDoc_STR("new() -> MhkCosts")},
		{"default",             MhkCosts_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> MhkCosts\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             MhkCosts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> MhkCosts\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   MhkCosts_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> MhkCosts\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "MhkCosts");


static int
MhkCostsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	MhkCosts_Type.tp_dict = PyDict_New();
	if (!MhkCosts_Type.tp_dict) { goto fail; }

	/// Add the MHKCosts type object to MhkCosts_Type
	if (PyType_Ready(&MHKCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkCosts_Type.tp_dict,
				"MHKCosts",
				(PyObject*)&MHKCosts_Type);
	Py_DECREF(&MHKCosts_Type);

	/// Add the Outputs type object to MhkCosts_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkCosts_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the MhkCosts type object to the module
	if (PyType_Ready(&MhkCosts_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"MhkCosts",
				(PyObject*)&MhkCosts_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot MhkCostsModule_slots[] = {
		{Py_mod_exec, MhkCostsModule_exec},
		{0, NULL},
};

static struct PyModuleDef MhkCostsModule = {
		PyModuleDef_HEAD_INIT,
		"MhkCosts",
		module_doc,
		0,
		MhkCostsModule_methods,
		MhkCostsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_MhkCosts(void)
{
	return PyModuleDef_Init(&MhkCostsModule);
}