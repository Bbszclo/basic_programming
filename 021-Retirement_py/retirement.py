def abstract_cal(initial_savings, info):

    initial_savings = initial_savings + initial_savings * info["rate_of_return"] + info["contribution"] 
    return initial_savings


def retirement(start_age, initial_savings, working_info, retired_info):
    """
    Prints the current status of an individual's retirement account.

    The dictionaries both have these fields:
        "months","contribution","rate_of_return"

    Args:
        start_age (int): At what age (in months) does the individual start
        initial_savings (float): initial savings in dollars
        working_info (dict): information about working
        retired_into (dict): information about retirement
    Returns:
        None
    """
    for index in range(working_info["months"]):
        total_months = start_age + index
        yr = total_months // 12
        m = total_months % 12
        print("Age {:3d} month {:2d} you have ${:,.2f}".format(yr, m, initial_savings))
        initial_savings = abstract_cal(initial_savings,working_info)


    for index2 in range(retired_info["months"]):
        total_months = start_age + working_info["months"] + index2
        yr = total_months // 12
        m = total_months % 12
        print("Age {:3d} month {:2d} you have ${:,.2f}".format(yr, m, initial_savings))
        initial_savings = abstract_cal(initial_savings, retired_info)

def main():
    start_age = 327
    initial_savings = 21345
    working_info={
    "months":489,
    "contribution":1000.0,
    "rate_of_return": 0.045/12
    }

    retired_info={
    "months":384,
    "contribution":-4000.0,
    "rate_of_return": 0.01/12
    }
    retirement(start_age, initial_savings, working_info, retired_info)

main()
        
