#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <stdexcept>

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

int read_int(const std::string& name) {
    int value = 0;

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

std::string read_percentage(const std::string& name) {
    std::string input;

    while (true) {
        std::cout << "Input the value of " << name << ": ";
        std::cin >> input;

        if (input.empty() || input.back() != '%') {
            std::cerr << "Input must end with '%'.\n";
        } else {
            return input;
        }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double percentage_to_decimal(std::string percentage) {
    std::string number_part = percentage.substr(0, percentage.size() - 1);
    
    try {
        return std::stod(number_part) / 100.0;
    } catch (...) {
        throw std::runtime_error("Invalid percentage format: " + percentage);
    }
}

int main() {
	double population = read_double("current population");
    double budget = read_double("current budget");
    int years = read_int("years");
    double birth_rate = percentage_to_decimal(read_percentage("birth rate"));

	for (int i = 0; i < years; i++) {
		population *= (1 + birth_rate);
		budget *= (1 + birth_rate);
	}

    std::cout << std::fixed << std::setprecision(2);
	std::cout << "Population after " << years << " years: " << population << ".\n"
              << "Budget after " << years << " years: $" << budget << ".\n";
}