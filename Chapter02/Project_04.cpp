#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <limits>

double read_inputs(const std::string& name) {
    double value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (!(std::cin >> value) || value <= 0) {
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
    std::string active;
    do {
        double received_amount = read_inputs("received amount");
        double rate = read_inputs("rate");
        double duration = read_inputs("duration");

        if (rate * (duration / 12.0) >= 1) {
            std::cerr << "Invalid inputs.\n";
            return 1;
        }

        double face_value = received_amount / (1 - (rate * (duration / 12.0)));
        double monthly_bill = face_value / duration;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Face value: " << face_value
            << "\nMonthly bill: " << monthly_bill << '\n';
        std::cout << "Play again? (y / n): ";
        std::cin >> active;
    } while (active == "y" || active == "Y");

    std::cout << '\n';

    return 0;
}