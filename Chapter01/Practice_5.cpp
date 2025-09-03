#include <iostream>
#include <iomanip>

double compute_area(double radius, double pi) {
    return pi * radius * radius;
}

int main() {
	double radius = 0, pi = 0;
    
	std::cout << "Input the radius:\n";
	if (!(std::cin >> radius) || radius < 0) {
        std::cerr << "Invalid input for radius.\n";
        return 1;
    }
	
    std::cout << "Input the value of pi:\n";
	if (!(std::cin >> pi) || pi < 3 || pi > 3.3) {
        std::cerr << "Invalid input for pi.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);
	std::cout << "The area of the circle is "
	          << compute_area(radius, pi)
	          << ".\n";
	return 0;
}
