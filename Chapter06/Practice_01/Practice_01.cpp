#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	const std::string default_path = "Practice_01_test.dat";
	const std::string filepath = (argc >= 2) ? argv[1] : default_path;
    // argc = len(argv) (=1 if no extra parameter entered)
    // argv[0] = the file name
    // (possibly exist) argv[1] = the first parameter entered in command

	std::ifstream fin(filepath);
	if (!fin) {
		std::cerr << "Failed to open file: " << filepath << '\n';
		return 1;
	}

	double num = 0.0;
	double sum = 0.0;
	while (fin >> num) sum += num;

	std::cout << "Total score: " << sum << '\n';
	return 0;
}
