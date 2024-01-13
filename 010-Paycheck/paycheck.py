hour=input("How many hours did the employee work?")
pay_rate=input("What is the employee's pay rate?")
hour=float(hour)
pay_rate=float(pay_rate)
if hour > 40 :
    pay_rate_over40 = pay_rate * 1.5
    total_pay = 40 * pay_rate + (hour - 40) * pay_rate_over40       
    print("Total pay:",total_pay)
    tax = total_pay * 0.2
    print("Taxes:",tax)
    net_pay = total_pay - tax
    print("Net pay:", net_pay)
else:
    total_pay = hour * pay_rate 
    print("Total pay:",total_pay)
    tax = total_pay * 0.2
    print("Taxes:",tax)
    net_pay = total_pay - tax
    print("Net pay:", net_pay)
