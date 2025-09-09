#include <iostream>
#include <iomanip>

int main()
{
	constexpr double annual_rate = 0.18;
    constexpr double monthly_payment = 50.0;          
    double bill = 1000.0;
    double monthly_rate = annual_rate / 12.0;

	int months = 0;
    double total_interest = 0.0;

	while (bill > 0)
	{
        double interest = bill * monthly_rate;
        
        total_interest += interest;

        if (bill + interest >= monthly_payment)
		{
            double paid = monthly_payment - interest;

            bill -= paid;
		}
		else
		{
			total_interest += interest;

            break;
		}

		months += 1;
	}

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Repayment period: " << months << " months.\n"
		      << "Total interest: $" << total_interest << ".\n";

	return 0;
}