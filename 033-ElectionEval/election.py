from sys import argv
import sys


def parse_state_information(filename):
    """
    Opens the state information file named in filename, loads all of the
    values, placing them in a single data structure. Returns that data
    structure.  You may created nested data structures.
    """
    state_info = {}
    f = open(filename, "r")
    info = f.read()
    f.close()
    info = info.strip()
    info = info.split("\n")
    print(info)
    info = sorted(info)
    print(info)
    for line in sorted(info):
        state, population, vote = line.split(":")
        state_info[state] = [population, vote]
    return state_info


def print_state_information(state_info):
    """
    For the state_info data structure (produced as a result),
    print all statues in alphabetical order using the string:
    "{}: Population - {:,d}, Electoral Votes: {:d}"
    """
    for key in sorted(state_info):
        population = int(state_info[key][0])
        votes = int(state_info[key][1])
        print(
            "{}: Population - {:,d}, Electoral Votes: {:d}".format(
                key, population, votes
            )
        )


def parse_vote_information(filename):
    """
    Opens the vote information file and returns the information
    in a data structure
    """
    f = open(filename, "r")
    state_vote = f.read()
    f.close()
    state_vote = state_vote.strip()
    state_vote = state_vote.split("\n")
    vote_info = {}
    for line in sorted(state_vote):
        state, vote = line.split(":")
        vote_info[state] = vote

    return vote_info


def count_electoral_votes(state_info, vote_info):
    """
    Counts and returns the number of electoral votes received by
    Candidate A in the election.

    For our purposes, Candidate A receives ALL electoral votes for a
    state if Candidate A receives strictly more than 50% of the votes in
    that State.  [Yes, we know that in the US there are a few states
    with more complex rules, but we will ignore them.  We will also
    ignore the electoral complexities of what would happen if a
    candidate received exactly 50%, and in this case, just say that
    Candidate A does not receive those electoral votes.  We are also
    assuming everyone in every state votes--while this doesn't happen in
    a real election, it is what we are doing here].
    """
    votes_A = 0
    if len(state_info) != len(vote_info):
        print("State_info and vote_info do not match. Please check.")
    else:
        for key in vote_info:
            if int(vote_info[key]) > int(state_info[key][0]) / 2:
                votes_A += int(state_info[key][1])
            elif int(vote_info[key]) == int(state_info[key][0]) / 2:
                continue
    return votes_A


def determine_winner(state_info, candidate_a_electoral_votes):
    """
    Determines whether Candidate A or Candidate B won based upon who
    won the majority of the electoral votes. If there is a tie, return None.
    Returns "A", "B", or None    the last one is the value None
    """
    total_vote = 0
    for key in state_info:
        total_vote += int(state_info[key][1])

    if candidate_a_electoral_votes > total_vote / 2:
        return "A"
    elif candidate_a_electoral_votes < total_vote / 2:
        return "B"
    else:
        return None


def print_winner(winner_name, number_of_votes):
    """
    Prints the winner.  If Candidate A or B wins, print
    "Candidate {} wins the election with {:d} votes" using the winner_name
    and number of Electoral College votes.

    If neither won the vote, print "It's a tie in the Electoral College."
    """
    if winner_name is not None:
        print(
            "Candidate {} wins the election with {:d} votes".format(
                winner_name, number_of_votes
            )
        )
    else:
        print("It's a tie in the Electoral College.")


def determine_recounts(state_info, vote_info):
    """
    Produces a list of strings, where each string represents information
    about a state the requires a recount. Recounts are required when a
    Candidate A is within +/ 0.5% of 50% of the votes.  So 49.50% or 50.50%
    require a recount, while 49.49% and 50.51% do not require a recount.

    Only include states that require a recount in the result. For each state
    that requires a recount, include a line of the form:
    "{} requires a recount (Candidate A has {:.2f}% of the vote)".
    """
    recount_list = []
    if len(state_info) != len(vote_info):
        print("State_info and vote_info do not match. Please check.")
    else:
        for key in state_info:
            state_vote = int(vote_info[key])
            vote_to_win = int(state_info[key][0])
            ratio = round(state_vote / vote_to_win * 100, 4)
            if ratio >= 49.50 and ratio <= 50.50:
                recount_list.append(
                    "{} requires a recount (Candidate A has {:.2f}% of the vote)".format(
                        key, ratio
                    )
                )
    return recount_list


def save_recounts(recount_list):
    """
    saves each entry of the list to a file named "recounts.txt".  The
    entries must be printed in alphabetical order.
    """
    f = open("recounts.txt", "wt")
    for item in recount_list:
        f.write(item)
        f.write("\n")
    f.close()


def determine_largest_win(state_info, vote_info):
    """
    Determines in which state Candidate A won the largest percentage
    of the vote.

    returns a string with the following format:
    "Candidate A won {} with {:.2f}% of the vote"

    where the first {} should be the name of the state, and the {.2f}
    should be the percentage of the vote won.  For example, it might return
    "Candidate A won California with 73.24% of the vote"

    None is returned if candidate A did not win a state
    """
    percent_dict = {}
    sort_percent_dict = {}
    if len(state_info) != len(vote_info):
        print("State_info and vote_info do not match. Please check.")
    else:
        for key in vote_info.keys():
            percent_dict[key] = round(
                int(vote_info[key]) / int(state_info[key][0]) * 100, 4
            )

        for index in range(len(percent_dict)):
            key = sorted(percent_dict, key=percent_dict.get, reverse=True)[
                index
            ]  # stock_prices是本来的dict
            value = percent_dict[key]
            sort_percent_dict[key] = value

    if len(sort_percent_dict) != 0:
        state = list(sort_percent_dict.keys())[0]
        percent = sort_percent_dict[state]
        message = "Candidate A won {} with {:.2f}% of the vote".format(state, percent)
    else:
        message = None

    return message


def process(state_info_filename, voter_info_filename):
    """
    Implements the "Several steps exist for this assignment" section
    Load and process a state information file
    Print state information
    Load and process the vote information file
    Determine who won the election
    Prints the winner to the console
    Determine which states require a recount
    Saves the recount information to a file
    Determine in which state, candidate A had the largest win
    Prints the largest win to the console
    """
    state_info = parse_state_information(state_info_filename)
    print_state_information(state_info=state_info)
    vote_info = parse_vote_information(voter_info_filename)
    electoral_votes = count_electoral_votes(state_info, vote_info)
    winner = determine_winner(state_info, electoral_votes)
    total_vote = 0
    for key in state_info:
        total_vote += int(state_info[key][1])
    if winner == "B":
        electoral_votes = total_vote - electoral_votes
    print_winner(winner, electoral_votes)
    recount_list = determine_recounts(state_info, vote_info)
    save_recounts(recount_list)
    state = determine_largest_win(state_info, vote_info)
    print(state)


if __name__ == "__main__":
    """implement checking command line arguments, call process()"""

    if len(sys.argv) != 3:
        print("Usage: python election.py state_info_filename voter_info_filename")
        sys.exit(101)
    else:
        state_info_filename = argv[1]
        vote_info_filename = argv[2]
        process(state_info_filename, vote_info_filename)
