#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>
#include <algorithm>

static std::array<double, 3> find_quartiles(std::vector<double> v) {
    std::array<double, 3> quartiles = {};
    if (v.empty()) return quartiles; // {0,0,0}

    std::sort(v.begin(), v.end());
    const int n = static_cast<int>(v.size());

    if (n == 1) return {v[0], v[0], v[0]};
    if (n == 2) return {v[0], (v[0]+v[1])/2.0, v[1]};
    if (n == 3) return {v[0], v[1], v[2]};

    const int r = n % 4;
    if (r == 0)
        quartiles = {(v[n/4-1]+v[n/4])/2.0, (v[n/2-1]+v[n/2])/2.0, (v[3*n/4-1]+v[3*n/4])/2.0};
    else if (r == 1)
        quartiles = {(v[(n-5)/4]+v[(n-1)/4])/2.0, v[(n-1)/2], (v[(3*n-3)/4]+v[(3*n+1)/4])/2.0};
    else if (r == 2)
        quartiles = {v[(n-2)/4], (v[n/2-1]+v[n/2])/2.0, v[(3*n-2)/4]};
    else // r == 3
        quartiles = {v[(n-3)/4], v[(n-1)/2], v[(3*n-1)/4]};

    return quartiles;
}

static void show_output(const std::array<double, 3>& quartiles) {
    std::cout << std::fixed << std::setprecision(2)
              << "First quartile: " << quartiles[0] << '\n'
              << "Second quartile (median): " << quartiles[1] << '\n'
              << "Third quartile: " << quartiles[2] << '\n';
}

int main(int argc, char* argv[]) {
    const std::string default_path = "Practice_03_test.dat";
	const std::string filepath = (argc >= 2) ? argv[1] : default_path;

	std::ifstream fin(filepath);
	if (!fin) {
		std::cerr << "Failed to open file: " << filepath << '\n';
		return 1;
	}

    std::vector<double> nums = {};
	double num = 0.0;
    while (fin >> num) {
        nums.push_back(num);
    }

    show_output(find_quartiles(nums));

	return 0;
}
