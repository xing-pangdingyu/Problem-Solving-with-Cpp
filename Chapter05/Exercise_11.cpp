#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

static double read_nonnegative_double(const std::string& name) {
    double value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value >= 0.0) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input a nonnegative decimal number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static double read_rate_0_to_1(const std::string& name) {
    double rate = 0;
    while (true) {
        std::cout << "Input the value of " << name << ": ";
        if ((std::cin >> rate) && rate >= 0.0 && rate <= 1.0) return rate;
        std::cerr << "Invalid input for " << name
                  << ". Please input a decimal in [0, 1].\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// tax_rate is the rate of tax e.g. 0.06 for 6%, and
// cost is the price before tax
static void apply_tax(double tax_rate, double& cost) {
    cost += cost * tax_rate;
}

int main() {
	double cost = read_nonnegative_double("price before tax");
    double tax_rate = read_rate_0_to_1("rate of tax");

	apply_tax(tax_rate, cost);

	std::cout << std::fixed << std::setprecision(2)
              << "After tax: $" << cost << ".\n";

	return 0;
}
