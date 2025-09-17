#include <iostream>
#include <random>
#include <vector>

static int draw_to_team(int ball, int t1, int t2, int t3, int t4) {
    if ((ball -= t1) <= 0) return 1;
    if ((ball -= t2) <= 0) return 2;
    if ((ball -= t3) <= 0) return 3;
    return 4;
}

int main() {
    int team_1 = 20;
    int team_2 = 10;
    int team_3 = 6;
    int team_4 = 4;

    int sum = team_1 + team_2 + team_3 + team_4;

	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> urn(1, sum);
    // An urn that contains 20 balls for team 1, 10 balls for team 2, etc.

    std::vector<int> teams_selected(4); // 0 = not selected, 1 = selected
    std::vector<int> order(4);          // order[i] = team picked at position i (0-based)

    for (int i = 0; i < 4; ++i) {
        while (true) {
            int one_draw = urn(gen);

            int team = draw_to_team(one_draw, team_1, team_2, team_3, team_4);

            if (teams_selected[team-1]) continue;
            teams_selected[team-1] = 1;
            order[i] = team;
            break;
        }
    }

    std::cout << "First pick: Team " << order[0] << '\n'
              << "Second pick: Team " << order[1] << '\n'
              << "Third pick: Team " << order[2] << '\n'
              << "Fourth pick: Team " << order[3] << '\n';

	return 0;
}
