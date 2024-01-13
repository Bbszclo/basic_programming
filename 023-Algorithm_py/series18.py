def series18(n):
    """Implement your function below"""
    value = - (n**2)
    print(value, end=" ")
    for index in range(1, 3*n, 1):
        value = value + 2 * index -1
        print(value, end=" ")
