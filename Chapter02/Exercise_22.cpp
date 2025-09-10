#include <iostream>

int main()
{
	double savings = 150.44, expenses = 120.0;

	if (savings >= expenses) {
		std::cout << "Solvent\n";
		savings -= expenses;
		expenses = 0;
	} else {
		std::cout << "Bankrupt\n";
    }

	return 0;
}