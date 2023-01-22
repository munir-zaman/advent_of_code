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
    // need to identify the common char in s1, s2 and s3

    // set p[priority - 1] to 1 if seen
    for (char& c: s1) {
        int priority_c = priority(c); // priority of char c
        p[priority_c - 1] = 1;
    }

    // set p[priority - 1] to 2 if 1 (seen in s1)
    for (char& c: s2) {
        int priority_c = priority(c); // priority of char c
        if (p[priority_c - 1] == 1) p[priority_c - 1] = 2;
    }

    // set p[priority - 1] to 3 if 2 (seen in s1 and s2)
    for (char& c: s3) {
        int priority_c = priority(c); // priority of char c
        if (p[priority_c - 1] == 2) p[priority_c - 1] = 3;
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
