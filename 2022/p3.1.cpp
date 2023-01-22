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

int total_priority(string s1, string s2) {
    vector<int> p(52);

    // set p[priority - 1] to 1 if seen
    for (char& c: s1) {
        int priority_c = priority(c); // priority of char c
        p[priority_c - 1] = 1;
    }

    // set p[priority - 1] to -1 if 1 (seen in s1)
    for (char& c: s2) {
        int priority_c = priority(c); // priority of char c
        if (p[priority_c - 1] == 1) p[priority_c - 1] = -1;
    }

    int total_p = 0;
    for (int i=0; i<52; i++) if (p[i] == -1) {total_p += (i+1);}
    return total_p;
}


int main() {
    ifstream file;
    file.open("p3_input");

    int sum_priority = 0;
    string line;
    while (getline(file, line)) {
        int len = line.size();
        string s1 = line.substr(0, len/2); // first half
        string s2 = line.substr(len/2, len/2); // second half
        
        sum_priority += total_priority(s1, s2);
    }
    cout << sum_priority << endl;
    file.close();
}
