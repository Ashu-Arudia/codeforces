#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    unordered_map<string, int> final_scores;
    vector<pair<string, int>> rounds;

    // Read rounds and calculate final scores
    for (int i = 0; i < a; i++) {
        string name;
        int score;
        cin >> name >> score;
        rounds.push_back({name, score});
        final_scores[name] += score;
    }

    // Find the maximum final score
    int max_score = INT_MIN;
    for (auto& it : final_scores) {
        if (it.second > max_score) {
            max_score = it.second;
        }
    }

    // Track running scores to find who reached max_score first
    unordered_map<string, int> running_scores;
    for (auto& round : rounds) {
        running_scores[round.first] += round.second;

        // If this player reached at least max_score and their final score equals max_score
        if (running_scores[round.first] >= max_score && final_scores[round.first] == max_score) {
            cout << round.first << "\n";
            break;
        }
    }

    return 0;
}
