#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <unordered_set>

int read_int_between_0_and_999(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value >= 0 && value <= 999) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer between 0 and 999.\n";
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

bool has_common(const std::vector<int>& a, const std::vector<int>& b) {
    std::unordered_set<int> s(a.begin(), a.end());

    for (int x : b) {
        if (s.count(x)) return true;
    }

    return false;
}

bool is_valid_temperature(int temperature, const std::vector<int>& broken) {
    std::vector<int> digits = last_k_digits(temperature, 3);

    return (!has_common(digits, broken));
}

int main() {
    std::vector<int> broken = {1, 4, 7};
	int temperature = read_int_between_0_and_999("desired temperature");

    if (is_valid_temperature(temperature, broken)) {
        std::cout << temperature << '\n';
    } else {
        int copy = temperature;
        while (!(is_valid_temperature(temperature, broken)) &&
               temperature <= 999) temperature++;
        while (!(is_valid_temperature(copy, broken)) && copy >= 0) copy--;

        std::cout << copy << ' ' << temperature << '\n';
    }

	return 0;
}
