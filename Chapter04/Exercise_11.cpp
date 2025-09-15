#include <iostream>
#include <string>
#include <limits>

bool in_order(int a, int b, int c) {
	return ((a <= b) && (b <= c));
}

int read_int(const std::string& name) {
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

int main() {
	int num_1 = read_int("the first integer");
    int num_2 = read_int("the second integer");
    int num_3 = read_int("the third integer");

    if (in_order(num_1, num_2, num_3)) {
        std::cout << "Ascending.\n";
    } else {
        std::cout << "Not ascending.\n";
    }

	return 0;
}
