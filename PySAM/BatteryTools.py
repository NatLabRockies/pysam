from typing import Union

import PySAM.Pvsamv1 as PVBatt
import PySAM.Battery as Batt
import PySAM.BatteryStateful as BattStfl

available_chems = ['leadacid', 'lfpgraphite', 'nmcgraphite', 'lmolto']


def battery_model_sizing(model, desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc=None, module_specs: dict=None, tol=0.05):
    """Sizes the battery model using its current configuration such as chemistry, cell properties, etc and modifies the model's power, capacity and voltage without changing its fundamental properties. The battery's thermal parameters (surface area and mass) are modified according to assumptions
    about the mass and volume per specific energy and assuming the battery is a cube. If the battery's thermal parameters should be sized according to a particular module's capacity and surface area,
    use the module_specs input.
    
    :param model: PySAM.Battery.Battery or PySAM.BatteryStateful.BatteryStateful
    :param float desired_power: For Battery, kWAC if AC-connected, kWDC otherwise. For BatteryStateful, battery kWDC.
    :param float desired_capacity: For Battery, kWhAC if AC-connected, kWhDC otherwise. For BatteryStateful, battery kWhDC.
    :param float desired_voltage: Volts
    :param bool, optional size_by_ac_not_dc: Sizes for power and capacity are on AC side not DC side of battery-inverter regardless of connection type.
    :param dict, optional module_specs: {capacity (float), surface_area (float)} Dictionary of battery module specifications for scaling surface area, assuming the battery is made of individual modules.

        capacity: float
            Capacity of a single battery module. For the Battery model, use kWhAC if AC-connected, use kWhDC otherwise. For the BatteryStateful model, use battery kWhDC.
        surface_area: float
            Surface area of as single battery module in m^2.
    """


    if module_specs is not None:
        if not module_specs.keys() == {'capacity', 'surface_area'}:
            raise TypeError("module_specs must contain 'capacity' and 'surface_area' keys only." )

    if type(model) == Batt.Battery or type(model) == PVBatt.Pvsamv1:
        size_battery(model, desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc, module_dict=module_specs, tol=tol)
    elif type(model) == BattStfl.BatteryStateful:
        size_batterystateful(model, desired_power, desired_capacity, desired_voltage, module_dict=module_specs)
    else:
        raise TypeError


def battery_model_change_chemistry(model, chem):
    """Changes the chemistry and cell properties of the battery to use defaults for that chemistry from BatteryStateful
    
    :param model: PySAM.Battery.Battery or PySAM.BatteryStateful.BatteryStateful
    :param str chem: Battery chemistry, 'leadacid', 'lfpgraphite', 'nmcgraphite', or 'lmolto'.
    """

    chem = chem.lower()
    if chem not in available_chems:
        raise NotImplementedError

    if type(model) == Batt.Battery or type(model) == PVBatt.Pvsamv1:
        chem_battery(model, chem)
    elif type(model) == BattStfl.BatteryStateful:
        chem_batterystateful(model, chem)
    else:
        raise TypeError


def size_battery(model, desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc=None, module_dict=None, tol=0.05):
    """Helper function for battery_model_sizing. Modifies Battery model with new sizing. For BatteryStateful use size_batterystateful.
    
    :param model: PySAM.Battery model
    :param float desired_power: Desired battery power, kWAC if AC-connected, kWDC otherwise.
    :param float desired_capacity: Desired battery capacity,  kWhAC if AC-connected, kWhDC otherwise.
    :param float desired_voltage: Desired battery voltage, V.
    :param bool,optional size_by_ac_not_dc: `True` sizes for power and capacity based on AC cpacities, `False` sizes for DC capacities.
    :param dict module_dict: {capacity (float), surface_area (float)} Battery module specs for scaling surface area.

        capacity: float
            Capacity of a single battery module in kWhAC if AC-connected or kWhDC if DC-connected.
        surface_area: float
            Surface area is of single battery module in m^2.
    
    :returns: Dictionary of of sizing parameters.
    :rtype: dict
    """

    if type(model) != Batt.Battery and type(model) != PVBatt.Pvsamv1:
        raise TypeError

    # Note - Size_battery is capable of throwing a general Exception - should this be narrowed locally?
    if module_dict is not None and size_by_ac_not_dc is not None:
        model.Size_battery(desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc=size_by_ac_not_dc, module_capacity=module_dict['capacity'], module_surface_area=module_dict['surface_area'], tol=tol)
    elif module_dict is not None:
        model.Size_battery(desired_power, desired_capacity, desired_voltage, module_capacity=module_dict['capacity'], module_surface_area=module_dict['surface_area'], tol=tol)
    elif size_by_ac_not_dc is not None:
        model.Size_battery(desired_power, desired_capacity, desired_voltage, size_by_ac_not_dc=size_by_ac_not_dc, tol=tol)
    else:
        model.Size_battery(desired_power, desired_capacity, desired_voltage, tol=tol)

    output_dict = {}
    
    # Note - these assume LiIon or Lead Acid. Need to rework for flow batteries. These were not implentened in 7.1.1, so need to update the function more generally if flow batteries are desired.
    output_dict['voltage'] = model.BatteryCell.batt_Vnom_default * model.BatterySystem.batt_computed_series
    output_dict['batt_computed_series'] = model.value('batt_computed_series')
    output_dict['batt_computed_strings'] = model.value('batt_computed_strings')
    if (model.BatterySystem.batt_ac_or_dc):
        output_dict['power'] = model.value('batt_power_discharge_max_kwac')
    else:
        output_dict['power'] = model.value('batt_power_discharge_max_kwdc')
    output_dict['batt_computed_bank_capacity'] = model.value('batt_computed_bank_capacity')
    output_dict['time_capacity'] = output_dict['batt_computed_bank_capacity'] / output_dict['power']
    output_dict['batt_power_discharge_max_kwdc'] = model.value('batt_power_discharge_max_kwdc')
    output_dict['batt_power_charge_max_kwdc'] = model.value('batt_power_charge_max_kwdc')
    output_dict['batt_current_charge_max'] = model.value('batt_current_charge_max')
    output_dict['batt_current_discharge_max'] = model.value('batt_current_discharge_max')
    output_dict['batt_power_discharge_max_kwac'] = model.value('batt_power_discharge_max_kwac')
    output_dict['batt_power_charge_max_kwac'] = model.value('batt_power_charge_max_kwac')

    return output_dict


def size_batterystateful(model: BattStfl.BatteryStateful, _, desired_capacity, desired_voltage, module_dict=None):
    """Helper function for ``battery_model_sizing()``. Modifies BatteryStateful model with new sizing. For Battery model, use ``size_battery()`` instead. Only battery side DC sizing.
    
    :param model: PySAM.Battery model
    :param _: Not used.
    :param float desired_capacity: kWhAC if AC-connected, kWhDC otherwise.
    :param float desired_voltage: Volts.
    :param dict module_dict: {capacity (float), surface_area (float)} Optional, module specs for scaling surface area.
    
        capacity: float
            Capacity of a single battery module in kWhAC if AC-connected, kWhDC otherwise.
        surface_area: float
            Surface area is of single battery module in m^2.

    :returns: Dictionary of sizing parameters.
    :rtype: dict
    """

    #
    # calculate size
    #
    if type(model) != BattStfl.BatteryStateful:
        raise TypeError

    original_capacity = model.ParamsPack.nominal_energy

    model.ParamsPack.nominal_voltage = desired_voltage
    model.ParamsPack.nominal_energy = desired_capacity

    #
    # calculate thermal
    #
    thermal_inputs = {
        'mass': model.ParamsPack.mass,
        'surface_area': model.ParamsPack.surface_area,
        'original_capacity': original_capacity,
        'desired_capacity': desired_capacity
    }
    if module_dict is not None:
        module_dict = {'module_'+k: v for k, v in module_dict.items()}
        thermal_inputs.update(module_dict)

    thermal_outputs = calculate_thermal_params(thermal_inputs)

    model.ParamsPack.mass = thermal_outputs['mass']
    model.ParamsPack.surface_area = thermal_outputs['surface_area']

def calculate_thermal_params(input_dict):
    """Calculates the mass and surface area of a battery by calculating from its current parameters the
    mass / specific energy and volume / specific energy ratios. If module_capacity and module_surface_area are provided, battery surface area is calculated by
    scaling module_surface_area by the number of modules required to fulfill desired capacity.
   
    :param dict input_dict: A dictionary of battery thermal parameters at original size. {mass (float), surface_area (float), original_capacity (float), desired_capacity (float), module_capacity (float, optional), surface_area (float, optional)}

        mass: float
            kg of battery at original size
        surface_area: float
            m^2 of battery at original size
        original_capacity: float
            Wh of battery
        desired_capacity: float
            Wh of new battery size
        module_capacity: float, optional
            Wh of module battery size
        module_surface_area: float, optional
            m^2 of module battery

    :returns: Dictionary of battery mass and surface area at desired size.
    :rtype: dict {mass (float), surface_area (float)} 

        mass: float
            kg of battery at desired size
        surface_area: float
            m^2 of battery at desired size
    """

    mass = input_dict['mass']
    surface_area = input_dict['surface_area']
    original_capacity = input_dict['original_capacity']
    desired_capacity = input_dict['desired_capacity']

    mass_per_specific_energy = mass / original_capacity

    volume = (surface_area / 6) ** (3/2)

    volume_per_specific_energy = volume / original_capacity

    output_dict = {
        'mass': mass_per_specific_energy * desired_capacity,
        'surface_area': (volume_per_specific_energy * desired_capacity) ** (2/3) * 6,
    }

    if input_dict.keys() >= {'module_capacity', 'module_surface_area'}:
        module_capacity = input_dict['module_capacity']
        module_surface_area = input_dict['module_surface_area']
        output_dict['surface_area'] = module_surface_area*desired_capacity/module_capacity

    return output_dict


def chem_battery(model: Union[Batt.Battery, PVBatt.Pvsamv1], chem):
    """Helper function for battery_model_change_chemistry().
    """

    if type(model) != Batt.Battery and type(model) != PVBatt.Pvsamv1:
        raise TypeError

    chem = chem.lower()
    if chem not in available_chems:
        raise NotImplementedError

    if chem == 'leadacid':
        model.BatteryCell.batt_chem = 0
    else:
        model.BatteryCell.batt_chem = 1

    original_capacity = model.value('batt_computed_bank_capacity')
    original_voltage = model.BatteryCell.batt_Vnom_default * model.BatterySystem.batt_computed_series
    if model.BatterySystem.batt_ac_or_dc:
        original_power = model.BatterySystem.batt_power_discharge_max_kwac
    else:
        original_power = model.BatterySystem.batt_power_discharge_max_kwdc

    params_dict = BattStfl.default(chem).export()

    for group in ('ParamsCell', 'ParamsPack'):
        for k, v in params_dict[group].items():
            if k == 'nominal_voltage' or k == "T_room_init":
                continue
            elif k == 'cycling_matrix':
                k = 'batt_lifetime_matrix'
            elif 'leadacid' in k:
                k = 'LeadAcid' + k[8:]
                if 'tn' not in k:
                    k += '_computed'
            elif k == 'h':
                k = 'batt_h_to_ambient'
            elif k == 'nominal_energy':
                k = 'batt_computed_bank_capacity'
            elif k == 'cap_vs_temp':
                pass
            else:
                k = 'batt_' + k

            model.value(k, v)

    battery_model_sizing(model, original_power, original_capacity, original_voltage)


def chem_batterystateful(model: BattStfl.BatteryStateful, chem):
    """
    Helper function for battery_model_change_chemistry
    """

    if type(model) != BattStfl.BatteryStateful:
        raise TypeError

    chem = chem.lower()

    if chem not in available_chems:
        raise NotImplementedError

    if chem == 'leadacid':
        model.ParamsCell.chem = 0
    else:
        model.ParamsCell.chem = 1

    original_capacity = model.ParamsPack.nominal_energy
    original_voltage = model.ParamsPack.nominal_voltage

    params_dict = BattStfl.default(chem).export()

    for group in ('ParamsCell', 'ParamsPack'):
        for k, v in params_dict[group].items():
            model.value(k, v)

    battery_model_sizing(model, -1, original_capacity, original_voltage)
