#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int priority(char c) {
    // returns the priority of char c
    if ('a' <= c && c <= 'z') return (int) (c - 'a' + 1);
    else return (int) (c - 'A' + 1 + 26);
}

int common_badge_priority(string s1, string s2, string s3) {
    vector<int> p(52);

    vector<string> strings = {s1, s2, s3};
    for (int k=0; k<3; k++) {
        // go through all the strings
        for (auto& c: strings[k]) {
            int priority_c = priority(c); // get priority of current char in string
            if (p[priority_c-1] == k) {p[priority_c - 1] = (k+1);}
        }
    }

    int total_p = 0;
    for (int i=0; i<52; i++) if (p[i] == 3) {total_p += (i+1);}
    return total_p;
}


int main() {
    ifstream file;
    file.open("p3_input");

    string line;
    vector<string> last_three_lines = {"", "", ""};
    int line_no_mod_3 = 0;
    int total = 0;
    while (getline(file, line)) {
        last_three_lines[line_no_mod_3] = line;
        if (line_no_mod_3 == 2) total += common_badge_priority(last_three_lines[0], last_three_lines[1], last_three_lines[2]);
        line_no_mod_3 = (line_no_mod_3 + 1) % 3;
    }
    cout << total << endl;
    file.close();
}
