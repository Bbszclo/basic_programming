from decimal import Decimal
from employee import Employee


class SalariedEmployee(Employee):
    """Salary Employee"""

    def __init__(self, name, job_title, annual_pay_rate):
        super().__init__(name, job_title)
        self.__annual_pay_rate = Decimal(annual_pay_rate)
        self.__periodic_rate = None

    @property
    def employee_type(self):
        return "salaried"
    
    @property
    def annual_pay_rate(self):
        return self.__annual_pay_rate

    @annual_pay_rate.setter
    def annual_pay_rate(self, new_rate):
        self.__annual_pay_rate = new_rate

    @property
    def periodic_rate(self):
        return self.__periodic_rate

    @periodic_rate.setter
    def periodic_rate(self, new_periodic_rate):
        self.__periodic_rate = Decimal(new_periodic_rate)

    def calculate_pay(self):
        """Assume the employees are paid bi-monthly (i.e., twice a month), so their periodic pay is 1/24 of their annual pay rate."""

        assert type(self.annual_pay_rate) is Decimal, "Annual pay rate not established"
        pay = self.annual_pay_rate
        periodic_rate = (1/24) * float(pay)
        return periodic_rate

    

