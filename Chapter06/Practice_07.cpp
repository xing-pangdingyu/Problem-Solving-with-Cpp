#include <iostream>
#include <fstream>
#include <string>

// This algorithm is used in merge sort
static void combine_numbers(std::ifstream& fin_1,
                            std::ifstream& fin_2,
                            std::ofstream& fout) {
    int a = 0, b = 0;
    bool hasA = static_cast<bool>(fin_1 >> a);
    bool hasB = static_cast<bool>(fin_2 >> b);

    while (hasA && hasB) {
        if (a <= b) {
            fout << a << '\n';
            hasA = static_cast<bool>(fin_1 >> a);
        } else {
            fout << b << '\n';
            hasB = static_cast<bool>(fin_2 >> b);
        }
    }

    while (hasA) {
        fout << a << '\n';
        hasA = static_cast<bool>(fin_1 >> a);
    }
    while (hasB) {
        fout << b << '\n';
        hasB = static_cast<bool>(fin_2 >> b);
    }
}

int main(int argc, char* argv[]) {
	const std::string default_1 = "Practice_07_nums_1.dat";
    const std::string default_2 = "Practice_07_nums_2.dat";
    const std::string default_out = "Practice_07_combined.dat";

    const std::string filepath_1 = (argc >= 2) ? argv[1] : default_1;
    const std::string filepath_2 = (argc >= 3) ? argv[2] : default_2;
    const std::string filepath_3 = (argc >= 4) ? argv[3] : default_out;

	std::ifstream fin_1(filepath_1);
	if (!fin_1) {
		std::cerr << "Failed to open file: " << filepath_1 << '\n';
		return 1;
	}

    std::ifstream fin_2(filepath_2);
	if (!fin_2) {
		std::cerr << "Failed to open file: " << filepath_2 << '\n';
		return 1;
	}
    
    std::ofstream fout(filepath_3);
	if (!fout) {
		std::cerr << "Failed to open file: " << filepath_3 << '\n';
		return 1;
	}

    combine_numbers(fin_1, fin_2, fout);

	return 0;
}
