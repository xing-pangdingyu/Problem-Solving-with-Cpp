#include <iostream>
#include <string>
#include <limits>

// Conditions: >= 1, <= 3, <= remaining
int read_int(const std::string& name, int remaining) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (std::cin >> value && value >= 1 && value <= 3 && value <= remaining) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input between 1 and 3, and <= " << remaining << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int robot_choice(int human_turn, int remaining) {
    if (remaining <= 0) return 0;
    if (remaining == 1) return 1;
    if (remaining >= 2 && remaining <= 4) return remaining - 1;
    return 4 - human_turn;
}

int main() {
	int toothpicks = 23;

	while (toothpicks > 0) {
        std::cout << "Toothpicks remaining: " << toothpicks << '\n';

		int human_turn = read_int("number of toothpicks to withdraw", toothpicks);
        toothpicks -= human_turn;

        if (toothpicks == 0) {
            std::cout << "You lose.\n";
            break;
        }

        int robot_turn = robot_choice(human_turn, toothpicks);
        toothpicks -= robot_turn;

        std::cout << "Robot took: " << robot_turn << '\n';

        if (toothpicks == 0) {
            std::cout << "You win.\n";
            break;
        }
	}

	return 0;
}
