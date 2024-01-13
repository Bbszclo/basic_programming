def array_max(array):
    """
    Finds the largest number in the list.
    Ignores elements that are not an int or a float

    Args:
        array (list): list of numbers (either float or int)

    Returns:
    Largest number in the list.  None if array is empty
    or if array is not a list.
    """
    
    number_list=[]

    #if type(array) not in [list]
    if type(array) is not list: # Not a list? return none
        return None
    
    for num in array:
        #if type(num) in [int,float] :
        if type(num) is int or type(num) is float:
            number_list.append(num)
    
    if not number_list: 
    #if there is no int/float in the number_list, return None
        return None
    
    max_num=max(number_list)
    return max_num
