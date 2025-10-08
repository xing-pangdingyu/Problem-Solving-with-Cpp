#include <iostream>
#include <fstream>
#include <string>

static void input_advices(std::ifstream& fin) {
    char next;

    while (fin.get(next)) std::cout << next; // Use get() to avoid omitting space and \n
}

static void output_advices(std::ofstream& fout) {
    std::cout << "Input advices (end with double Return):\n";

    char next;
    while (std::cin.get(next)) {
        fout << next;
        if (next == '\n') {
            int peeked = std::cin.peek(); // Check the next character
            if (peeked == '\n') {
                std::cin.get(); // Consume the second newline
                fout << '\n';
                break;
            }
        }
    }
}

int main(int argc, char* argv[]) {
	const std::string default_path = "Practice_05_advices.dat";
	const std::string filepath = (argc >= 2) ? argv[1] : default_path;

	std::ifstream fin(filepath);
	if (!fin) {
		std::cerr << "Failed to open file: " << filepath << '\n';
		return 1;
	}
    input_advices(fin);
    fin.close();
    
    // Append new advices to preserve existing file content
    std::ofstream fout(filepath, std::ios::app);
	if (!fout) {
		std::cerr << "Failed to open file: " << filepath << '\n';
		return 1;
	}
    output_advices(fout);
    fout.close();

	return 0;
}
