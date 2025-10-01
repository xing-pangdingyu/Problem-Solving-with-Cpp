#include <iostream>
#include <string>
#include <limits>
#include <cassert>

static int read_int_in_range(const std::string& name, int a, int b) {
    assert(a <= b);
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name
                  << " in [" << a << ", " << b << "]: ";

        if (std::cin >> value && value >= a && value <= b) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer in ["
                  << a << ", " << b << "].\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Precondition: 0 < coin_value < 100, 0 <= amount_left < 100
// Postcondition: num has been set as the maximum number of coins that
//                can be obtained from amount_left, and amount_left has
//                been decreased by this amount.
static void compute_coins(int coin_value, int& num, int& amount_left) {
    assert(coin_value > 0 && coin_value < 100);
    assert(amount_left >= 0 && amount_left < 100);
    num = amount_left / coin_value;
    amount_left %= coin_value;
}

static void show_output(int cents, int quarters, int dimes, int pennies) {
    std::cout << cents << (cents == 1 ? " cent = " : " cents = ")
              << quarters << (quarters == 1 ? " quarter + " : " quarters + ")
              << dimes << (dimes == 1 ? " dime + " : " dimes + ")
              << pennies << (pennies == 1 ? " penny\n" : " pennies\n");
}

int main() {
	int cents = 0, quarters = 0, dimes = 0, pennies = 0;
    constexpr int cents_per_quarter = 25;
    constexpr int cents_per_dime = 10;
    constexpr int cents_per_penny = 1;

    cents = read_int_in_range("cents", 1, 99);

    const int cents_copy = cents;

    compute_coins(cents_per_quarter, quarters, cents);
    compute_coins(cents_per_dime, dimes, cents);
    compute_coins(cents_per_penny, pennies, cents);

	show_output(cents_copy, quarters, dimes, pennies);

	return 0;
}
