class MhkCosts(object):
	def assign(self, dict):
		pass

	def replace(self, dict):
		pass

	def value(self, name, value=None):
		pass

	def unassign(self, name):
		pass

	def execute(self, int_verbosity):
		pass

	def export(self):
		pass

	def get_data_ptr(self):
		pass

	def __getattribute__(self, *args, **kwargs):
		pass

	def __init__(self, *args, **kwargs):
		pass

	class MHKCosts(object):
		def assign(self, dict): 
			pass
	
		def replace(self, dict): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		assembly_and_install_cost_input = float
		assembly_and_install_cost_method = float
		assembly_and_install_cost_rvalue = float
		assembly_and_install_cost_total = float
		development_cost_input = float
		development_cost_method = float
		development_cost_rvalue = float
		development_cost_total = float
		device_rated_power = float
		devices_per_row = float
		elec_infras_cost_input = float
		elec_infras_cost_method = float
		elec_infras_cost_modeled = float
		elec_infras_cost_rvalue = float
		elec_infras_cost_total = float
		eng_and_mgmt_cost_input = float
		eng_and_mgmt_cost_method = float
		eng_and_mgmt_cost_rvalue = float
		eng_and_mgmt_cost_total = float
		insurance_during_construction_cost_input = float
		insurance_during_construction_cost_method = float
		insurance_during_construction_cost_rvalue = float
		lib_tidal_device = str
		lib_wave_device = str
		library_or_input_wec = float
		maintenance_cost_input = float
		maintenance_cost_method = float
		maintenance_cost_rvalue = float
		maintenance_cost_total = float
		marine_energy_tech = float
		mooring_found_substruc_cost_input = float
		mooring_found_substruc_cost_method = float
		mooring_found_substruc_cost_rvalue = float
		mooring_found_substruc_cost_total = float
		operations_cost_input = float
		operations_cost_method = float
		operations_cost_rvalue = float
		operations_cost_total = float
		other_financial_cost_input = float
		other_financial_cost_method = float
		other_financial_cost_rvalue = float
		other_infrastructure_cost_input = float
		other_infrastructure_cost_method = float
		other_infrastructure_cost_rvalue = float
		other_infrastructure_cost_total = float
		plant_commissioning_cost_input = float
		plant_commissioning_cost_method = float
		plant_commissioning_cost_rvalue = float
		power_takeoff_system_cost_input = float
		power_takeoff_system_cost_method = float
		power_takeoff_system_cost_total = float
		project_contingency_cost_input = float
		project_contingency_cost_method = float
		project_contingency_cost_rvalue = float
		reserve_accounts_cost_input = float
		reserve_accounts_cost_method = float
		reserve_accounts_cost_rvalue = float
		reserve_accounts_cost_total = float
		site_access_port_staging_cost_input = float
		site_access_port_staging_cost_method = float
		site_access_port_staging_cost_rvalue = float
		site_access_port_staging_cost_total = float
		structural_assembly_cost_input = float
		structural_assembly_cost_method = float
		structural_assembly_cost_rvalue = float
		structural_assembly_cost_total = float
		system_capacity = float


	class Outputs(object):
		def assign(self, dict): 
			pass
	
		def replace(self, dict): 
			pass
	
		def export(self) -> dict:
			pass
	
		def __init__(self, *args, **kwargs): 
			pass


		assembly_and_install_cost = float
		assembly_and_install_cost_modeled = float
		development_cost = float
		development_cost_modeled = float
		eng_and_mgmt_cost = float
		eng_and_mgmt_cost_modeled = float
		insurance_during_construction_cost = float
		insurance_during_construction_cost_modeled = float
		maintenance_cost = float
		maintenance_cost_modeled = float
		mooring_found_substruc_cost = float
		mooring_found_substruc_cost_modeled = float
		operations_cost = float
		operations_cost_modeled = float
		other_financial_cost = float
		other_financial_cost_modeled = float
		other_infrastructure_cost = float
		other_infrastructure_cost_modeled = float
		plant_commissioning_cost = float
		plant_commissioning_cost_modeled = float
		power_takeoff_system_cost = float
		power_takeoff_system_cost_modeled = float
		project_contingency_cost = float
		project_contingency_cost_modeled = float
		reserve_accounts_cost = float
		reserve_accounts_cost_modeled = float
		site_access_port_staging_cost = float
		site_access_port_staging_cost_modeled = float
		structural_assembly_cost = float
		structural_assembly_cost_modeled = float




def default(config) -> MhkCosts:
	pass

def new() -> MhkCosts:
	pass

def wrap(ssc_data_t) -> MhkCosts:
	pass

def from_existing(model, config="") -> MhkCosts:
	pass

__loader__ = None 

__spec__ = None
