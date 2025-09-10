#include <iostream>
#include <limits>
#include <string>
#include <cctype>

enum class Gesture { Paper = 0, Rock = 1, Scissors = 2 };
enum class Outcome { Tie, P1, P2 };

Gesture read_paper_rock_scissors(const std::string& name) {
    char ch = 0;

    while (true) {
        std::cout << "Input for " << name << " (P/R/S): ";

        if (std::cin >> ch) {
            switch (ch) {
                case 'P':
                return Gesture::Paper;
                case 'R':
                return Gesture::Rock;
                case 'S':
                return Gesture::Scissors;
                default:
                std::cerr << "Invalid input for " << name << ".\n";
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Outcome paper_rock_scissors(Gesture player_1, Gesture player_2) {
    int a = static_cast<int>(player_1);
    int b = static_cast<int>(player_2);

    int diff = (a - b + 3) % 3;
    
    if (diff == 0) return Outcome::Tie;
    if (diff == 1) return Outcome::P2;
    return Outcome::P1;
}

const char* describe(Gesture winner, Gesture loser) {
    if (winner == Gesture::Paper && loser == Gesture::Rock) return "Paper covers rock.";
    if (winner == Gesture::Rock && loser == Gesture::Scissors) return "Rock breaks scissors.";
    if (winner == Gesture::Scissors && loser == Gesture::Paper) return "Scissors cut paper.";
    return "";
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

int main()
{
    do {
        Gesture player_1 = read_paper_rock_scissors("Player 1");
        Gesture player_2 = read_paper_rock_scissors("Player 2");

        Outcome o = paper_rock_scissors(player_1, player_2);

        if (o == Outcome::Tie) {
            std::cout << "Nobody wins.\n";
        } else if (o == Outcome::P2) {
            std::cout << describe(player_2, player_1) << " Player 2 wins.\n";
        } else {
            std::cout << describe(player_1, player_2) << " Player 1 wins.\n";
        }
    } while (read_yes_no());

	return 0;
}
