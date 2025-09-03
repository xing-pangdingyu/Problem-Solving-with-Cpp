#include <iostream>

int compute_total_cents(int quarters, int dimes, int nickels) {
	return quarters * 25 + dimes * 10 + nickels * 5;
}

int read_coin_count(const std::string& name) {
    int value = 0;
    std::cout << "Input the number of " << name << ":\n";
    if (!(std::cin >> value) || value < 0) {
        throw std::runtime_error("Invalid input for " + name + '.');
    }
    return value;
}

int main() {
	try {
		int quarters = read_coin_count("quarters");
		int dimes = read_coin_count("dimes");
		int nickels = read_coin_count("nickels");

		std::cout << "The total value is "
			  << compute_total_cents(quarters, dimes, nickels)
			  << " cents.\n";
		return 0;
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
}
