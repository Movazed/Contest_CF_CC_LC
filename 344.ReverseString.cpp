#include <iostream>
#include <string>
#include <cmath> // for abs function

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int total = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            total += abs(s[i] - s[i + 1]);
        }
        return total;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "abcd";
    string test2 = "hello";
    string test3 = "world";
    string test4 = "algorithm";
    string test5 = "score";

    // Output results
    cout << "Score of \"" << test1 << "\": " << solution.scoreOfString(test1) << endl;
    cout << "Score of \"" << test2 << "\": " << solution.scoreOfString(test2) << endl;
    cout << "Score of \"" << test3 << "\": " << solution.scoreOfString(test3) << endl;
    cout << "Score of \"" << test4 << "\": " << solution.scoreOfString(test4) << endl;
    cout << "Score of \"" << test5 << "\": " << solution.scoreOfString(test5) << endl;

    return 0;
}
