def power(x,y):
    """
    computes x to the y power,
    0 to the 0 is undefined in mathematics, we specify that 0 to the 0 shall be 1 for this function
    y is a nonnegative integer.
    """
    if x == 0 and y == 0:
        return 1
    elif y == 0:
        return 1
    else:
        return x * power(x,y-1)
        

