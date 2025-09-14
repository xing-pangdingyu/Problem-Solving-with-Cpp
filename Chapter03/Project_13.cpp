#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm> // std::adjacent_find
#include <numeric> // std::accumulate

int read_nonnegative_int(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value >= 0) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input a nonnegative integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int read_positive_int(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value > 0) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input a positive integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<int> last_k_digits(int n, int k) {
    std::vector<int> digits(k);

    for (int i = k - 1; i >= 0; --i) {
        digits[i] = n % 10;
        n /= 10;
    }

    return digits;
}

bool is_valid(const std::vector<int>& digits, int date) {
    constexpr int THRESHOLD = 64;

    int size = digits.size();

    int sum = std::accumulate(digits.begin(), digits.end(), 0);

    if (sum % date == 0) return true;

    auto it = std::adjacent_find(digits.begin(), digits.end(),
                                 [](int a, int b) { return a * b >= THRESHOLD; });
    return it == digits.end();
}

int main() {
    constexpr int LENGTH_PIN = 5;

    int pin = read_nonnegative_int("PIN");
    int date = read_positive_int("date");

	std::vector<int> digits = last_k_digits(pin, LENGTH_PIN);

	if (is_valid(digits, date)) {
        std::cout << "Valid PIN.\n";
    } else {
        std::cout << "Invalid PIN.\n";
    }

	return 0;
}
