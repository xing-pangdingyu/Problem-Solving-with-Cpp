#include <iostream>
#include <limits>

int read_even() {
    int value = 0;

    while (true) {
        std::cout << "Input an even number: ";

        if ((std::cin >> value) && value % 2 == 0) {
            return value;
        }
        std::cerr << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
	int sum = 0;

    while (true) {
        int even_num = read_even();

        if (even_num == 0) { // Sentinel value = 0
            break;
        }

        sum += even_num;
    }

	std::cout << "Sum = " << sum << '\n';

	return 0;
}
