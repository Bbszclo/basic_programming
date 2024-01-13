def compute_average(l):
    """
    Computes the average of list, ignoring any entries that 
    are not numbers (floats or ints)

    Args:
    l(list): list of items to compute the average
 
    returns:
    average of the numbers in the list
    
    raises:
    ValueError if the argument is not a list or if the list does not contain any numbers
    """
    # TODO: Implement function
    total = 0
    count = 0
    
    if type(l) is not list:
        raise ValueError("Wrong exception type raised")
    
    if len(l) == 0:
        raise ValueError("Wrong exception type raised")
    
    for item in l:
        if type(item) is int or type(item) is float:
            total += item
            count += 1
    
    if count == 0:
        raise ValueError("Wrong exception type raised")
    



    average = total / count
    return average



    
    



