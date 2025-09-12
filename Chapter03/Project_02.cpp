#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>

constexpr double EPS = 1e-9;
bool almost_equal(double a, double b, double eps = EPS) {
    return std::fabs(a - b) <= eps * std::max(1.0, std::max(std::fabs(a), std::fabs(b)));
}

bool is_isosceles(double s_1, double s_2, double s_3) {
    if (almost_equal(s_1, s_2) || almost_equal(s_1, s_3) ||
        almost_equal(s_2, s_3)) return true;
    return false;
}

bool is_equilateral(double s_1, double s_2, double s_3) {
    if (almost_equal(s_1, s_2) && almost_equal(s_2, s_3)) return true;
    return false;
}

double read_positive_double(const std::string& name) {
    double value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value > 0.0) {
            return value;
        }
        std::cerr << "Invalid input for " << name << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    constexpr double equilateral_angle = 60.0;
    
	double side_1 = read_positive_double("the first side");
    double side_2 = read_positive_double("the second side");
    double side_3 = read_positive_double("the third side");
	
    std::cout << std::fixed << std::setprecision(2);
	if (is_equilateral(side_1, side_2, side_3)) {
        std::cout << "Equilateral. Angles: ";
        for (int i = 0; i < 3; i++) std::cout << equilateral_angle << ' ';
    } else if (is_isosceles(side_1, side_2, side_3)) {
        double diff_angle_in_isosceles = read_positive_double("the different angle (Plz < 180 too lazy to write in function)");

        double other_angle = (180.0 - diff_angle_in_isosceles) / 2.0;

        std::cout << "Isosceles. Angles: " << diff_angle_in_isosceles << ' '
                  << other_angle << ' ' << other_angle << '\n';
    } else {
        std::cout << "Scalene.";
    }

    std::cout << '\n';

	return 0;
}