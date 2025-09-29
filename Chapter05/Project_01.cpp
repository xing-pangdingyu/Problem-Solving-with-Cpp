#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <iomanip>

static double read_double(const std::string& name) {
    double value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (std::cin >> value) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input a decimal number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static void read_input(double& temperature, bool& is_fahrenheit) {
    temperature = read_double("temperature");
    while (true) {
        std::cout << "Fahrenheit or Celsius (f/c): ";
        char c;
        if (!(std::cin >> c)) continue;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (c == 'f') {
            is_fahrenheit = true;
            return;
        }
        if (c == 'c') {
            is_fahrenheit = false;
            return;
        }
        std::cerr << "Please enter 'f' or 'c'.\n";
    }
}

static void f_to_c(double f, double& result) {
    result = (f - 32.0) * 5.0 / 9.0;
}

static void c_to_f(double c, double& result) {
    result = c * 9.0 / 5.0 + 32.0;
}

static void show_output(double temperature, double result, bool is_fahrenheit) {
    std::cout << temperature;
    if (is_fahrenheit) {
        std::cout << "F";
    } else {
        std::cout << "C";
    }
    std::cout << " = " << result;
    if (is_fahrenheit) {
        std::cout << "C";
    } else {
        std::cout << "F";
    }
    std::cout << '\n';
}

static bool read_yes_no() {
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
	double temperature, result;
    bool is_fahrenheit;

    std::cout << std::fixed << std::setprecision(2);
    do {
        read_input(temperature, is_fahrenheit);
        if (is_fahrenheit) {
            f_to_c(temperature, result);
        } else {
            c_to_f(temperature, result);
        }
        show_output(temperature, result, is_fahrenheit);
    } while (read_yes_no());

    return 0;
}
