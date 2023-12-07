
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    ifstream file;
    file.open("p1_input"); // open input file 

    long long sum = 0;
    while (getline(file, line)){
        int first = -1;
        int last = -1;
        for (int i = 0; i < line.size(); i++) {
            if (isdigit(line[i])) {
                if (first == -1) first = atoi(&line[i]);
                last = atoi(&line[i]);
            }
        }
        sum += 10LL*first + last;
    }
    std::cout << sum << "\n";
}
