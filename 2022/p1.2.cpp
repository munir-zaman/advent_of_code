#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string line;
    ifstream file;
    file.open("p1_input"); // open input file
    
    vector<int> calories; 
    int current_sum = 0;
    while (getline(file, line)){
        if (line != "") { current_sum += stoi(line); }
        else {
            calories.push_back(current_sum);
            current_sum = 0;
        }
    }
    
    sort(calories.rbegin(), calories.rend());
    int total = calories[0] + calories[1] + calories[2];
    cout << "RESULT: " << total << endl;
}
