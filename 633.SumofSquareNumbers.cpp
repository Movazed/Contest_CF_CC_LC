#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int divisor = 2; divisor * divisor <= c; divisor++) {
            if (c % divisor == 0) {
                int exponentCount = 0;
                while (c % divisor == 0) {
                    exponentCount++;
                    c /= divisor;
                }
                if (divisor % 4 == 3 && exponentCount % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};

int main() {
    Solution solution;
    int testCases[] = {5, 3, 10, 25, 34, 0, 1, 2};
    int numOfTestCases = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numOfTestCases; i++) {
        int c = testCases[i];
        bool result = solution.judgeSquareSum(c);
        cout << "judgeSquareSum(" << c << ") = " << (result ? "true" : "false") << endl;
    }

    return 0;
}
