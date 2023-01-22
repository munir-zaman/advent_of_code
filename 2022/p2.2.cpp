#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// 0 = X lost
// 3 = Y draw
// 6 = Z win

// A, 1 = rock
// B, 2 = paper
// C, 3 = scissors

// {{other, outcome, you}, ...}
vector<vector<int>> strategy = {
    {'A', 'X', 3},
    {'A', 'Y', 1},
    {'A', 'Z', 2},

    {'B', 'X', 1},
    {'B', 'Y', 2},
    {'B', 'Z', 3},

    {'C', 'X', 2},
    {'C', 'Y', 3},
    {'C', 'Z', 1},
};


int get_score(char outcome, char other) {
    int score = 0;
    score += (outcome - 88) * 3;

    for (auto m: strategy) if (m[0] == other && m[1] == outcome) score += m[2];
    return score;
}

int main()
{
    string line;
    ifstream file;
    file.open("p2_input");

    int total_score = 0;
    while (getline(file, line)) {
        char outcome = line[2];
        char other = line[0];
        total_score += get_score(outcome, other);
    }
    cout << "SCORE: " << total_score << endl;
}
