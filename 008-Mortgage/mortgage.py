p = input("What is the amount borrowed?")
r = input("What is the annual interest rate - express this as a decimal such as 0.07 for 7%?")

# place your code here after this line
p=float(p)
r=float(r)/12
n = 360

rate = (1+r) ** n
upper = r * rate
down = rate - 1
A = p * (upper / down)
payment_amount = int(A*100)/100
print(payment_amount)
