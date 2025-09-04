#include <iostream>

int main()
{
	std::string character;

    std::cout << "Input a character: ";

    if (!(std::cin >> character)) {
        std::cerr << "Invalid input for character.\n";
        return 1;
    }

    if (character.size() != 1) {
        std::cerr << "Error: please enter exactly one character.\n";
        return 1;
    }

	std::cout << "  " << character << character << character << "\n "
	          << character << "  " << character << "\n"
	          << character << "\n" << character << "\n"
	          << character << "\n" << character << "\n"
	          << character << "\n " << character << "  " << character
              << "\n  " << character << character << character << "\n";

	return 0;
}