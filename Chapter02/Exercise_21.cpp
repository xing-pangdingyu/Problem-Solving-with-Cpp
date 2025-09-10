#include <iostream>
#include <string>
#include <limits>

int read_int(const std::string& name) {
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

int main() {
	int score = read_int("score");

	if (score > 100) {
		std::cout << "High\n";
	} else {
		std::cout << "Low\n";
	}

	return 0;
}