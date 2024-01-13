def print_receipt(subtotal, tax_rate, tip_rate):
    """
    This function aims to compute and print out part of the bill/receipt that is provided to customers. 

    Args:
        subtotal (float): The subtotal of the bill.
        tax_rate (float): The state tax rate.
        tip_rate (float): The tip rate that the customers will like to tip on the waiter. 

    Prints:
        The part of the bill/recepit that is provided to the customers(see the example).
    
    Examples:
        When the subtotal is 10.00, tax_rate is 0.1 and tip_date is 0.2, print the following receipt out:

   Subtotal: $     10.00
        Tax: $      0.50
        Tip: $      2.00
              ==========
      Total: $     12.50
    """
    tax = subtotal * tax_rate
    tip = subtotal * tip_rate
    total = subtotal + tax + tip
    wide=21
    
    subtotal="{:10.2f}".format(subtotal)
    tax="{:10.2f}".format(tax)
    tip="{:10.2f}".format(tip)
    total="{:10.2f}".format(total)

    print("Subtotal: $".rjust(11)+subtotal)
    print("Tax: $".rjust(11)+tax)
    print("Tip: $".rjust(11)+tip)
    print("==========".rjust(wide))
    print("Total: $".rjust(11)+total)