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
    
    int MAX = 0;
    int current_sum = 0;
    while (getline(file, line)){
        if (line != "") { current_sum += stoi(line); }
        else {
            MAX = max(MAX, current_sum);
            current_sum = 0;
        }
    }
    cout << "MAX: " << MAX << endl;
}
