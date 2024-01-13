def convert_mass(value, current, target):
    """
    This function aims to change a mass's value from one unit provided to the unit desired.

    Args:
        value (float): The number for the current mass.
        current (string): The unit currently used for the mass.
        target (string): The unit to convert the mass into.

    Returns:
        target_unit_mass(float): return the number for the targeted mass

    Examples:
        10.1 Pound to Grams: 10.1pound --> 1 pound=0.45kilo -->10.1Pound= 10.1*0.45(convert to kg)/0.001(convert to gram) = 4581.28 grams
    """
    current_target_dict={
        "Kilogram": 1.0,
        "Pound": 0.453592,
        "Stone": 6.35029,
        "Jin": 0.5,
        "Seer": 1.25,
        "Gram": 0.001,
        "Oka": 1.2829
    }

    target_unit_mass=value * current_target_dict[current] / current_target_dict[target]
    print(current_target_dict[current])
    return target_unit_mass
