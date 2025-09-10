#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

double read_double(const std::string& name) {
    double value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (!(std::cin >> value) || value < 0) {
            std::cerr << "Invalid input for " << name << ".\n";
        } else {
            return value;
        }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
    constexpr double liters_per_gallon = 3.78533;
	double gallons = read_double("gallons");
	
	double liters = gallons * liters_per_gallon;

    std::cout << std::fixed << std::setprecision(4);
	std::cout << gallons << " gallons = " << liters << " liters.\n";
	
	return 0;
}