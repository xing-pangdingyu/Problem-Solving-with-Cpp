#include <iostream>
#include <string>
#include <cctype>
#include <limits>

enum class Rank { Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5,
                  Six = 6, Seven = 7, Eight = 8, Nine = 9,
                  Ten = 10, Jack = 10, Queen = 10, King = 10 };

int read_int_between_2_and_5(const std::string& name) {
    int value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if ((std::cin >> value) && value >= 2 && value <= 5) {
            return value;
        }
        std::cerr << "Invalid input for " << name
                  << ". Please input an integer between 2 and 5.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Rank read_rank(const std::string& name) {
    std::string str;

    while (true) {
        std::cout << "Input " << name << ": ";

        if ((std::cin >> str) && str.size() == 1) {
            char ch = static_cast<char>(std::tolower(static_cast<unsigned char>(str[0])));

            if (ch == '2') return Rank::Two;
            if (ch == '3') return Rank::Three;
            if (ch == '4') return Rank::Four;
            if (ch == '5') return Rank::Five;
            if (ch == '6') return Rank::Six;
            if (ch == '7') return Rank::Seven;
            if (ch == '8') return Rank::Eight;
            if (ch == '9') return Rank::Nine;
            if (ch == 't') return Rank::Ten;
            if (ch == 'j') return Rank::Jack;
            if (ch == 'q') return Rank::Queen;
            if (ch == 'k') return Rank::King;
            if (ch == 'a') return Rank::Ace;
        }
        std::cerr << "Invalid input for " << name << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
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

int main() {
    do {
        int num_cards = read_int_between_2_and_5("number of cards (2-5)");
        int sum = 0;
        bool have_ace = false; // At most one Ace = 11

        for (int i = 0; i < num_cards; i++) {
            Rank next_card = read_rank("the next card value (2-9, t, j, q, k, a)");

            if (next_card == Rank::Ace) have_ace = true;

            sum += static_cast<int>(next_card);
        }

        if (have_ace && sum <= 11) sum += 10;
        
        if (sum <= 21) {
            std::cout << "Score: " << sum << '\n';
        } else {
            std::cout << "Busted.\n";
        }
    } while (read_yes_no());
	return 0;
}
