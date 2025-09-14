#include <iostream>
#include <random>
#include <iomanip>

bool win_monty_hall(int original, int prize, bool change_door) {
    return change_door ? (original != prize) : (original == prize); // condition ? value_if_true : value_if_false
}

int main() {
    constexpr int trials = 10000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> door_dist(1, 3);

    int win_change = 0; int win_keep = 0;
    for (int i = 0; i < trials; ++i) {
        int original = door_dist(gen);
        int prize = door_dist(gen);
        if (win_monty_hall(original, prize, true)) win_change++;
        if (win_monty_hall(original, prize, false)) win_keep++;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Change choice: " << 100.0 * win_change / trials << "%\n"
              << "Keep choice: " << 100.0 * win_keep / trials << "%\n";

	return 0;
}
