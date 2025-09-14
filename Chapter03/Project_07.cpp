#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <cctype>
#include <iomanip>

long double read_double(const std::string& name) {
    long double value = 0;

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

bool read_yes_no() {
    std::string s;
    while (true) {
        std::cout << "Play again? (y/n): ";
        if (!(std::cin >> s)) return false;
        char c = 0;
        for (char ch : s) if (!std::isspace(static_cast<unsigned char>(ch))) { c = ch; break; }
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (c == 'y') return true;
        if (c == 'n') return false;
        std::cerr << "Please enter 'y' or 'n'.\n";
    }
}

int main()
{
    constexpr int max_n = 100;
    constexpr int columns = 5;

    std::cout << std::fixed << std::setprecision(7);
	do {
        long double x = read_double("x");

	    long double ex = std::expl(x);

        int n = 0;
        long double sum = 1.0L, term = 1.0L;

        while (n <= max_n - 1) {
            for (int i = 1; i <= columns; ++i) {
                n++;
                if (n > max_n) break;
                term *= x / static_cast<long double>(n);
                sum += term;

                std::cout << static_cast<double>(sum) << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "True value: e^{" << static_cast<double>(x)
                  << "} = " << static_cast<double>(ex) << '\n';
	} while (read_yes_no());

	return 0;
}
