def make_change(amount):
    """
    For a given amount, returns a dictionary containing the smallest number of bills and coins that add up to that number.
    Args:
        amount (float): a float amount that represent the amount that need to be change in bills and coins

    Returns:
        change_menu (dict): A dictionary containing the smallest number of bills and coins that add up to the amount

        $ python3 test.py 443.20
        $100.00: 4
        $20.00: 2
        $2.00: 1
        $1.00: 1
        $0.10: 2
    }
    """

    change = {
        100.00: 0,
        50.00: 0,
        20.00: 0,
        10.00: 0,
        5.00: 0,
        2.00: 0,
        1.00: 0, 
        0.25: 0,
        0.10: 0,
        0.05: 0, 
        0.01: 0 
    }

    for key in change:
        change[key] = amount // key
        amount -= change[key] * float(key)
        amount=round(amount,2)
        if amount == 0:
            break

    new_change={}
    for key,value in change.items():
            if value !=0:
                new_change[key] = value
    change = new_change

    return change

def print_change(change):
    """
    Print out the change dictionary.

    Args:
        change (dictionary): A dictionary containing the smallest number of bills and coins that add up to the amount

    Returns:
        None

    Examples:
        $ python3 test.py 443.20
        $100.00: 4
        $20.00: 2
        $2.00: 1
        $1.00: 1
        $0.10: 2
    }

        
    """
    for key in change:
        print("${:.2f}: {:d}".format(key, int(change[key])))





