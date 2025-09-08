#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>

double read_inputs(const std::string& name) {
    double value = 0;

    while (true) {
        std::cout << "Input the value of " << name << ": ";

        if (!(std::cin >> value) || value < 0) {
            std::cerr << "Invalid input for " << name << ".\n";
        } else {
            return value;
        }
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
	    double mark = read_inputs("mark");
        double pass_mark = read_inputs("pass mark");
		if (mark >= pass_mark) {
			std::cout << "Exam passed, proceed to the next semester.\n";
        } else {
            double diff = std::max(0.0, pass_mark - mark);
			std::cout << "Exam failed, still " << diff
                      << " marks needed to pass.\n";
		}
	} while (read_yes_no());

	return 0;
}