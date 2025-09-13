#include <iostream>
#include <string>
#include <limits>
#include <array>

int read_int_between_0_and_9999(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value >= 0 && value <= 9999) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer between 0 and 9999.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::array<int, 4> last_four_digits(int n) {
    std::array<int, 4> digits{};

    n %= 10000;

    digits[0] = n / 1000; n %= 1000;
	digits[1] = n / 100; n %= 100;
	digits[2] = n / 10;
	digits[3] = n % 10;

    return digits;
}

int main() {
	int num = read_int_between_0_and_9999("a positive integer up to 4 digits");

	std::array<int, 4> four_digits = last_four_digits(num);

	std::cout << "The number: " << num << '\n'
		      << "Digit at ones: " << four_digits[3] << '\n'
              << "Digit at tens: " << four_digits[2] << '\n'
              << "Digit at hundreds: " << four_digits[1] << '\n'
              << "Digit at thousands: " << four_digits[0] << '\n';

	return 0;
}
