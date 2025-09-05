#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <stdexcept>

double sqrt_newton(double n, double tolerance = 0.01) {
    double r = 0, previous_guess = 1, error = 0;
    double guess = n / 2.0;

    do {
		previous_guess = guess;
		r = n / guess;
		guess = (guess + r) / 2;
        error = std::abs(guess - previous_guess);
	} while (error > tolerance);

    return guess;
}

double read_inputs(const std::string& name) {
    double value = 0;

    std::cout << "Input " << name << ": ";

    if (!(std::cin >> value) || value < 0) {
        throw std::runtime_error("Invalid input for " + name + ".");
    }

    return value;
}

int main() {
    // n: the number being calculated the square root
    // guess: initial guess, set as n/2.
    double n = read_inputs("n");
    double n_sqrt = sqrt_newton(n);

    std::cout << std::fixed << std::setprecision(5);
	std::cout << "The appropriate value of the square root of " << n
	          << " is " << n_sqrt << ".\n";

    return 0;
}