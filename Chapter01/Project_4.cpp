#include <iostream>
#include <iomanip>

double compute_pressure(double mass, double depth, double volume,
                        double acceleration = 32.0) {
    if (volume <= 0) {
        throw std::runtime_error("Error: Volume must be > 0.");
    }
    return (mass * depth * acceleration) / volume;
}

double read_values(const std::string& name) {
    double value = 0;
    std::cout << "Input the value of " << name << ":\n";
    if (!(std::cin >> value) || value < 0) {
        throw std::runtime_error("Invalid input for " + name + ".");
    }
    return value;
}

int main() {
    try {
	    double mass = read_values("mass");
        double depth = read_values("depth");
        double volume = read_values("volume");

        std::cout << std::fixed << std::setprecision(2);
	    std::cout << "The pressure is "
	              << compute_pressure(mass, depth, volume)
	              << '.';
    } catch (const std::runtime_error& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
}
