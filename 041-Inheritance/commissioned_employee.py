from decimal import Decimal
from salaried_employee import SalariedEmployee
# from employee import Employee


class CommissionedEmployee(SalariedEmployee):
    """Commisioned Employee"""

    def __init__(self, name, job_title, annual_pay_rate, period_gross_sales):
        super().__init__(name, job_title,annual_pay_rate)
        self.__annual_pay_rate = Decimal(annual_pay_rate)
        self.__period_gross_sales= Decimal(period_gross_sales)
        self.__periodic_rate = None

    @property
    def employee_type(self):
        return "commissioned"
    
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

    @property
    def period_gross_sales(self):
        return self.__period_gross_sales
    
    @period_gross_sales.setter
    def period_gross_sales(self, new_period_gross_sales):
        self.__period_gross_sales = Decimal(new_period_gross_sales)



    def calculate_pay(self):
        """A commissioned employee's salary is computed as the pay they would receive as a salaried employee plus 5% of their period gross sales."""

        assert type(self.annual_pay_rate) is Decimal, "Annual pay rate not established"
        pay = self.annual_pay_rate
        gross_pay = self.period_gross_sales
        periodic_rate = (1/24) * float(pay) + 0.05 * float(gross_pay)
        return periodic_rate

    

