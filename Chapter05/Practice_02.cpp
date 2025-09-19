#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cmath>

constexpr double METERS_PER_FOOT = 0.3048;
constexpr double INCHES_PER_FOOT = 12.0;
constexpr double CENTIMETERS_PER_METER = 100.0;

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

static void input_feet_inches(double& feet, double& inches) {
    feet = read_nonnegative_double("number of feet");
    inches = read_nonnegative_double("number of inches");
    if (inches >= INCHES_PER_FOOT) {
        feet += std::floor(inches / INCHES_PER_FOOT);
        inches = std::fmod(inches, INCHES_PER_FOOT);
    }
}

static double feet_to_meters(double feet) {
    return feet * METERS_PER_FOOT;
}

static double inches_to_feet(double inches) {
    return inches / INCHES_PER_FOOT;
}

// Convert to feet, then convert to meters
static double feet_inches_to_meters(double feet, double inches) {
    return feet_to_meters(feet + inches_to_feet(inches));
}

static void output_meters_centimeters(double meters) {
    long long total_cm = static_cast<long long>(std::llround(meters * CENTIMETERS_PER_METER));
    long long whole_meters = total_cm / 100;
    long long centimeters = total_cm % 100;

    std::cout << "Equivalence: " << whole_meters << " meters "
              << centimeters << " centimeters.\n";
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
	double feet, inches;

    do {
        input_feet_inches(feet, inches);
        output_meters_centimeters(feet_inches_to_meters(feet, inches));
    } while (read_yes_no());

	return 0;
}
