#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>

constexpr double GALLONS_PER_LITER = 0.264179;

double read_positive_double(const std::string& name) {
    double value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value > 0.0) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input a positive decimal number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double liters_to_gallons(double liters) {
    return liters * GALLONS_PER_LITER;
}

bool read_yes_no() {
    while (true) {
        std::cout << "Play again? (y/n): ";
        char c;
        if (!(std::cin >> c)) return false;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (c == 'y') return true;
        if (c == 'n') return false;
        std::cerr << "Please enter 'y' or 'n'.\n";
    }
}

int main() {

	do {
		double liters = read_positive_double("liters of gasoline");
        double miles = read_positive_double("miles traveled");

        double gallons = liters_to_gallons(liters);

		std::cout << std::fixed << std::setprecision(2)
                  << "Miles per gallon: " << (miles / gallons) << '\n';
	} while (read_yes_no());

    return 0;
}
