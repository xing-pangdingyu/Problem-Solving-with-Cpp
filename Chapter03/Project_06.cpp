#include <iostream>
#include <string>
#include <limits>
#include <cctype>

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

// F(0) = 1, F(1) = 1, F(n) = F(n-1) + F(n-2)
unsigned long long nth_fibonacci(int n) {
    if (n <= 1) return 1ULL;

    unsigned long long a = 1;
    unsigned long long b = 1;

    for (int i = 2; i <= n; i++) {
        unsigned long long next = a + b;

        a = b;
        b = next;
    }

    return b;
}

bool read_yes_no() {
    std::string s;
    while (true) {
        std::cout << "Play again? (y/n): ";
        if (!(std::cin >> s)) return false;
        char c = 0;
        for (char ch : s) if (!std::isspace(static_cast<unsigned char>(ch))) { c = ch; break; }
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (c == 'y') return true;
        if (c == 'n') return false;
        std::cerr << "Please enter 'y' or 'n'.\n";
    }
}

int main() {
    constexpr int cycle_days = 5;

    do {
        unsigned long long initial_size =
            static_cast<unsigned long long>(read_nonnegative_int("initial size of crud"));
        int days = read_nonnegative_int("number of days");

        int cycles = days / cycle_days;

        std::cout << "Current population: "
                << initial_size * nth_fibonacci(cycles) << '\n';
    } while (read_yes_no());

	return 0;
}
