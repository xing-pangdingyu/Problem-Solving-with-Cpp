#include <iostream>
#include <random>
#include <vector>
#include <iomanip>

// Shooter accuracies: Aaron=1/3, Bob=1/2, Charlie=1
static constexpr double kAccuracies[3] = {1.0/3.0, 1.0/2.0, 1.0};

static void shoot(bool& targetAlive, double accuracy, std::mt19937& gen) {
    std::bernoulli_distribution hit(accuracy);
    if (hit(gen)) targetAlive = false;
}

// Main strategy: choose the most accurate alive opponent as the target
static int choose_target(int shooter, const bool alive[3]) {
    int target = -1;
    double best = -1.0;
    for (int i = 0; i < 3; ++i) {
        if (i == shooter) continue;
        if (alive[i] && kAccuracies[i] > best) {
            best = kAccuracies[i];
            target = i;
        }
    }
    return target;
}

// Simulate one duel. If strategy2 is true, Aaron intentionally misses first shot.
static int simulate_duel(std::mt19937& gen, bool strategy2) {
    bool alive[3] = {true, true, true};
    bool aaronFirstShot = strategy2;

    auto alive_count = [&](){ return (alive[0]?1:0) + (alive[1]?1:0) + (alive[2]?1:0); };

    while (alive_count() > 1) {
        for (int shooter = 0; shooter < 3 && alive_count() > 1; ++shooter) {
            if (!alive[shooter]) continue;
            if (shooter == 0 && aaronFirstShot) { // Aaron intentionally misses the first shot
                aaronFirstShot = false;
                continue;
            }
            int target = choose_target(shooter, alive);
            if (target >= 0) {
                shoot(alive[target], kAccuracies[shooter], gen);
            }
        }
    }
    for (int i = 0; i < 3; ++i) if (alive[i]) return i + 1;
    return 0;
}

static void show_output(const std::vector<int>& winner_count) {
    int total = winner_count[0] + winner_count[1] + winner_count[2];

    std::cout << std::fixed << std::setprecision(2)
              << "Total: " << total << " games\n"
              << "Aaron   : " << 100.0 * static_cast<double>(winner_count[0]) / static_cast<double>(total) << "%\n"
              << "Bob     : " << 100.0 * static_cast<double>(winner_count[1]) / static_cast<double>(total) << "%\n"
              << "Charlie : " << 100.0 * static_cast<double>(winner_count[2]) / static_cast<double>(total) << "%\n";
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Strategy 1:
    std::vector<int> winner_count(3);
	for (int i = 0; i < 100000; ++i) {
		winner_count[simulate_duel(gen, false)-1] += 1;
	}
    // (Math work) Probability of winning:
    // Aaron:   13/36 = 36.11%
    // Bob:      5/12 = 41.67%
    // Charlie:  2/9  = 22.22%
    show_output(winner_count);


    // Strategy 2:
    winner_count = {0, 0, 0};
    for (int i = 0; i < 100000; ++i) {
		winner_count[simulate_duel(gen, true)-1] += 1;
	}
    // (Math work) Probability of winning:
    // Aaron:   5/12 = 41.67%
    // Bob:     1/4  = 25.00%
    // Charlie: 1/3  = 33.33%
    show_output(winner_count);

	return 0;
}
