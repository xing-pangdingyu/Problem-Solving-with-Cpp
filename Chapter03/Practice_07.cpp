#include <iostream>
#include <string>
#include <limits>

int read_nonnegative_int(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value >= 0) {
            return value;
        }
        std::cerr << "Invalid input for " << name << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
	int max_age = -1;

	while (true) {
		int age = read_nonnegative_int("age of the next student (0 to stop)");

        if (age == 0) break; // 0 as sentinel
		if (age > max_age) max_age = age;
	}

    if (max_age == -1) {
        std::cout << "No students entered.\n";
    } else {
        std::cout << "The oldest: " << max_age << " years old.\n";
    }

	return 0;
}
