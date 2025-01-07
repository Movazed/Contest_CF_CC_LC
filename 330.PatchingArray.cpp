#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int result = 0;
        size_t i = 0;

        while(miss <= n){
            if (i < nums.size() && nums[i] <= miss){
                miss += nums[i];
                i++;
            } else {
                miss += miss;
                result++;
            }
        }
        return result;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 3};
    int n = 6;

    // Create an instance of Solution
    Solution solution;

    // Call the minPatches method and print the result
    int result = solution.minPatches(nums, n);
    cout << "Minimum patches required: " << result << endl;

    return 0;
}
