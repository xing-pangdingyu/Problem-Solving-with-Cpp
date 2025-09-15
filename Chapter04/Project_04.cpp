#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <array>

static int read_int_between_0_and_9999(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (std::cin >> value && value >= 0 && value <= 9999) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer between 0 and 9999.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

static std::vector<int> last_k_digits(int n, int k) {
    std::vector<int> digits(k);

    for (int i = k - 1; i >= 0; --i) {
        digits[i] = n % 10;
        n /= 10;
    }

    return digits;
}

static int sum_vector(const std::vector<int>& v) {
    int sum = 0;

    for (int x : v) sum += x;

    return sum;
}

static std::string num_to_word(int n) {
    static const std::array<std::string, 20> up_to_19 {
        "zero", "one", "two", "three", "four", "five", "six", "seven",
        "eight", "nine", "ten", "eleven", "twelve", "thirteen",
        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
        "nineteen"
    };
    static const std::array<std::string, 8> tens {
        "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    if (n > 99 || n < -99) return "out of range";

    std::string str;
    if (n < 0) {
        str += "negative ";
        n = -n;
    }

    if (n < 20) {
        str += up_to_19[static_cast<std::size_t>(n)];
        return str;
    }

    int t = n / 10;
    int u = n % 10;
    str += tens[static_cast<std::size_t>(t - 2)];
    if (u != 0) {
        str += " ";
        str += up_to_19[static_cast<std::size_t>(u)];
    }
    return str;
}

int main() {
	int num = read_int_between_0_and_9999("a 4-digit number");

    while (num) {
        std::vector<int> digits = last_k_digits(num, 4);
        
        std::cout << "Sum of digits of number " << num << " is "
                  << num_to_word(sum_vector(digits)) << ".\n";
        
        num /= 10;
    }

	return 0;
}
