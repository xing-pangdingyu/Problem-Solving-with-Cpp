#include <iostream>
#include <array>
#include <string>
#include <limits>
#include <cctype>
#include <utility>

static int read_int(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (std::cin >> value) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static std::pair<int, int> find_extreme_values(const std::array<int, 4>& a) {
	int max = a[0];
    int min = a[0];

    for (int i = 1; i < a.size(); ++i) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    return {max, min};
}

static bool read_yes_no() {
    while (true) {
        std::cout << "Play again? (y/n): ";
        char c;
        if (!(std::cin >> c)) return false;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard leftovers
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (c == 'y') return true;
        if (c == 'n') return false;
        std::cerr << "Please enter 'y' or 'n'.\n";
    }
}

int main() {
    do {
        std::array<int, 4> numbers;

        for (int i = 0; i < numbers.size(); ++i) {
            numbers[i] = read_int("the next number");
        }

        std::pair<int, int> extreme_values = find_extreme_values(numbers);
        // Or, auto [min, max] = std::minmax_element(numbers.begin(), numbers.end());

        std::cout << "Maximum: " << extreme_values.first << '\n'
                  << "Minimum: " << extreme_values.second << '\n';
    } while (read_yes_no());

	return 0;
}
