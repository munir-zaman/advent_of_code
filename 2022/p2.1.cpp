#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int get_score(char you, char other) {
    int score = 0;
    score += you - 88 + 1;

    if ( (you - 88) == (other - 65) ) { score += 3; } // draw
    else if (you == 'X' && other == 'C') { score += 6; } // rock && scissors
    else if (you == 'Y' && other == 'A') { score += 6; } // paper && rock
    else if (you == 'Z' && other == 'B') { score += 6; } // scissors && paper
    else { score += 0; } // lost

    return score;
}

int main()
{
    string line;
    ifstream file;
    file.open("p2_input");

    int total_score = 0;
    while (getline(file, line)) {
        char you = line[2];
        char other = line[0];
        total_score += get_score(you, other);
    }
    cout << "SCORE: " << total_score << endl;
}
