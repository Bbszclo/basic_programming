from sys import argv
import sys

months = ["01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"]


def parse_equity_data(filename):
    """
    read csv file and parse down equity data
    """
    try:
        equity_dict = {}
        f = open(filename, "r")
        equity = f.read()
        f.close()
        equity = equity.strip()
        equity = equity.split("\n")
        equity_input_check(equity)
        for index in sorted(equity[1:]):
            date, index_level, dividend = index.split(",")
            equity_dict[date] = [index_level, dividend]
        equity = sorted(equity)
        return equity_dict  # only one dictionary with each key_value pair as date: [index_level, dividend]
    except Exception as e:
        print(e)
        sys.exit(20)


def parse_bond_data(filename):
    """
    read csv file and parse down bond data
    """
    try:
        bond_dict = {}
        f = open(filename, "r")
        bond = f.read()
        f.close()
        bond = bond.strip()
        bond = bond.split("\n")
        bond_input_check(bond)
        for line in sorted(bond[1:]):
            date, percentage_rate = line.split(",")
            bond_dict[date] = percentage_rate
        bond = sorted(bond)
        return bond_dict
    except Exception as e:
        print(e)
        sys.exit(30)


def equity_input_check(equity_list):
    """
    check for input data issue with the S&P data file
    possible issues cheked include:
    Date, Index_value, Div(one of more columns missing)
    Date, Index_value and Div are not digits
    time continuity issue
    """
    equity_list = sorted(equity_list[1:])
    next_month = equity_list[0].split(",")[0].split(".")[1]
    next_year = equity_list[0].split(",")[0].split(".")[0]
    for equity in equity_list:
        data = equity.split(",")
        if len(data) != 3:
            print("not enough equity argv")
            sys.exit(20)
        try:
            float(data[0])
            float(data[1])
            float(data[2])
            months.index(data[0].split(".")[1])
        except Exception as e:
            print(e)
            print("bad data type for equity")
            sys.exit(20)
        if next_month != data[0].split(".")[1] or next_year != data[0].split(".")[0]:
            print("bad data for equity")
            sys.exit(20)
        next_month = months[(months.index(data[0].split(".")[1]) + 1) % 12]
        next_year = data[0].split(".")[0]
        if next_month == "01":
            next_year = str(int(data[0].split(".")[0]) + 1)


def bond_input_check(bond_list):
    """
    check for ssue with the bonds data file
    possible issues cheked include:
    Date, bondrate(one of more columns missing)
    bondrate and date are not digits
    time continuity issue
    """
    bond_list = sorted(bond_list[1:])
    next_month = bond_list[0].split(",")[0].split(".")[1]
    next_year = bond_list[0].split(",")[0].split(".")[0]
    for bond in bond_list:
        data = bond.split(",")
        if len(data) != 2:
            print("not enough bond argv")
            sys.exit(30)
        try:
            float(data[0])
            float(data[1])
            months.index(data[0].split(".")[1])
        except Exception as e:
            print(e)
            print("bad data type for bond")
            sys.exit(30)
        if next_month != data[0].split(".")[1] or next_year != data[0].split(".")[0]:
            print("bad data for bond")
            sys.exit(30)
        next_month = months[(months.index(data[0].split(".")[1]) + 1) % 12]
        next_year = data[0].split(".")[0]
        if next_month == "01":
            next_year = str(int(data[0].split(".")[0]) + 1)


def time_range_check(start_date, end_date, equity_dict, bond_dict):
    """
    check for bad date type and possible bad date input
    possible issues cheked include:
    start_date and end_date should be 1-12
    start_date should be eariler than end_date
    start_date and end_date should be in the csv range (both bond and equity)
    """
    start_date_temp = start_date.split(".")
    end_date_temp = end_date.split(".")
    if (
        len(start_date_temp) != 2
        or len(end_date_temp) != 2
        or start_date_temp[1] < "01"
        or start_date_temp[1] > "12"
        or end_date_temp[1] < "01"
        or end_date_temp[1] > "12"
        or end_date < start_date
    ):
        sys.exit(10)
    first_month = list(equity_dict.keys())[0]
    last_month = list(equity_dict.keys())[-1]
    if start_date < first_month:
        print("start_time too early")
        sys.exit(20)
    if end_date > last_month:
        print("end_date too late")
        sys.exit(20)
    first_month = list(bond_dict.keys())[0]
    last_month = list(bond_dict.keys())[-1]
    if start_date < first_month:
        print("start_time too early")
        sys.exit(30)
    if end_date > last_month:
        print("end_date too late")
        sys.exit(30)


def ROR_calc(equity_dict, bond_dict, current_month, previous_month):
    """
    sp500's ROR, dividends ROR and bond ROR's calculation
    """
    SPROR = (
        float(equity_dict[current_month][0]) / float(equity_dict[previous_month][0]) - 1
    )
    DivROR = float(equity_dict[current_month][1]) / (
        12 * float(equity_dict[current_month][0])
    )
    bondROR = float(bond_dict[current_month]) / 12 / 100
    return SPROR, DivROR, bondROR


def date_generator(equity_dict, start_date, end_date):
    """
    date generator to store a data_list for writing portfolio.csv
    """
    date_list = []
    for key in equity_dict.keys():
        if key < start_date:
            continue
        if key > end_date:
            break
        date_list.append(key)
    return date_list


def general_strat(previous_balanace, interest_rate, contribution):
    """
    calculate general strategy:
    new balance = previous balance +
        the interest it earns based on that month's rate of return +
        the monthly contribution.
    """
    new_balance = previous_balanace * (1 + interest_rate) + contribution
    return new_balance


def strategy_one(equity_dict, bond_dict, start_date, end_date):
    """
    compute Portfolio Strategy 1: Invest in Equities
    """
    contribution = 100
    previous_balance = 0
    strategy_one_list = []
    previous_month = list(equity_dict.keys())[0]
    for key in equity_dict.keys():
        if key < start_date:
            previous_month = key
            continue
        if key > end_date:
            break
        if key.split(".")[1] == "01" and key != start_date:
            contribution *= 1.025
        SPROR, DivROR, _ = ROR_calc(equity_dict, bond_dict, key, previous_month)
        totalROR = SPROR + DivROR
        new_balance = general_strat(previous_balance, totalROR, contribution)
        strategy_one_list.append(new_balance)
        previous_balance = new_balance
        previous_month = key

    return strategy_one_list


def strategy_two(equity_dict, bond_dict, start_date, end_date):
    """
    compute Portfolio Strategy 2: Invest in Bonds
    """
    contribution = 100
    previous_balance = 0
    strategy_two_list = []
    for key in bond_dict.keys():
        if key < start_date:
            continue
        if key > end_date:
            break
        if key.split(".")[1] == "01" and key != start_date:
            contribution *= 1.025
        _, _, bondROR = ROR_calc(equity_dict, bond_dict, key, key)
        new_balance = general_strat(previous_balance, bondROR, contribution)
        strategy_two_list.append(new_balance)
        previous_balance = new_balance
    return strategy_two_list


def strategy_three(equity_dict, bond_dict, start_date, end_date):
    """
    compute Portfolio Strategy 3: Lifecycle Investment
    """
    contribution = 100
    lifecycle = 1
    previous_month = list(equity_dict.keys())[0]
    previous_balance = 0
    strategy_three = []
    for key in bond_dict.keys():
        if key < start_date:
            previous_month = key
            continue
        if key > end_date:
            break
        if key.split(".")[1] == "01" and key != start_date:
            contribution *= 1.025
            lifecycle -= 0.02
        SPROR, DivROR, bondROR = ROR_calc(equity_dict, bond_dict, key, previous_month)
        interest_rate = (SPROR + DivROR - bondROR) * lifecycle + bondROR
        new_balance = general_strat(previous_balance, interest_rate, contribution)
        strategy_three.append(new_balance)
        previous_balance = new_balance
        previous_month = key
    return strategy_three


# def csv_generator(strategy_one, strategy_two, strategy_three,date_generator)


def process(equity_file_name, bond_file_name, start_date, end_date):
    """
    read historical data,
    calculate rates of return,
    and output the cumulative investment for each of the three investment strategies to a file.
    """
    equity_dict = parse_equity_data(equity_file_name)
    bond_dict = parse_bond_data(bond_file_name)
    time_range_check(start_date, end_date, equity_dict, bond_dict)
    strategyOne = strategy_one(equity_dict, bond_dict, start_date, end_date)
    strategyTwo = strategy_two(equity_dict, bond_dict, start_date, end_date)
    strategyThree = strategy_three(equity_dict, bond_dict, start_date, end_date)
    date_list = date_generator(equity_dict, start_date, end_date)
    with open("portfolio.csv", "w") as f:
        f.writelines("Date,StrategyOne,StrategyTwo,StrategyThree\n")
        for index in range(len(strategyOne)):
            f.writelines(
                str(date_list[index])
                + ","
                + "{:.2f}".format(strategyOne[index])
                + ","
                + "{:.2f}".format(strategyTwo[index])
                + ","
                + "{:.2f}".format(strategyThree[index])
                + "\n"
            )


if __name__ == "__main__":
    """
    call the above process function and to ensure a proper command-line arguments
    example call: python3 retirement.py sp_data.csv bond_data.csv 1971.12 2017.12
    """

    if len(argv) != 5:
        print(
            "Usage: python3 retirement.py equity_file_name bond_file_name beginning_date end_date"
        )
        sys.exit(10)

    else:
        equity_file_name = argv[1]
        bond_file_name = argv[2]
        start_date = argv[3]
        end_date = argv[4]

        process(equity_file_name, bond_file_name, start_date, end_date)
