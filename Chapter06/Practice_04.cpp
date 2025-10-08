#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <utility>

// Welford's algorithm: returns {mean, stddev} (population stddev by default)
static std::pair<double, double> mean_and_stddev(std::ifstream& fin, bool sample = false) {
    long long n = 0;
    double mean = 0.0;
    double M2 = 0.0;
    double x = 0.0;

    while (fin >> x) {
        n++;
        double delta = x - mean;
        mean += delta / static_cast<double>(n);
        double delta2 = x - mean;
        M2 += delta * delta2;
    }

    if (n == 0) return {0.0, 0.0};
    double variance;
    if (sample) {
        if (n < 2) return {mean, 0.0};
        variance = M2 / static_cast<double>(n - 1);
    } else {
        variance = M2 / static_cast<double>(n);
    }
    return {mean, std::sqrt(variance)};
}

static void show_output(double mean, double std_dev) {
    std::cout << std::fixed << std::setprecision(2)
              << "Mean: " << mean << '\n'
              << "Standard deviation: " << std_dev << '\n';
}

int main(int argc, char* argv[]) {
	const std::string default_path = "Practice_04_test.dat";
	const std::string filepath = (argc >= 2) ? argv[1] : default_path;

	std::ifstream fin(filepath);
	if (!fin) {
		std::cerr << "Failed to open file: " << filepath << '\n';
		return 1;
	}

    auto [mean, std_dev] = mean_and_stddev(fin, false);
    show_output(mean, std_dev);

	return 0;
}
