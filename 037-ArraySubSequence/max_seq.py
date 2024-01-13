def max_seq(l):
    """
    max_seq returns a the maximum increasing contiguous subsequence in the list.
    (as determined by length).  If two or more subsequences have equal lengths,
    return the first subsequence found.
   
    Args:
    l(list): list of numbers

    Returns:
    the maximum increasing contiguous subsequence as a list. If the l is empty,
    an empty list is returned

    Raises:
    TypeError if the list contains an item that is not arithmetically 
    compatible with ints and floats
    """
    new_list = []
    max_list = []
    if len(l) == 0:
        return []
    else:
        for item in l:
            if type(item) is not int and type(item) is not float:
                raise TypeError
            elif len(new_list) == 0:
                new_list.append(item)
            elif item > new_list[-1]:
                new_list.append(item)
            else:
                new_list=[item]

            if len(new_list) > len(max_list):
                max_list = new_list
    return max_list

# print(max_seq([1,2,3,4,2,3,4,5,6,7,1,2]))

