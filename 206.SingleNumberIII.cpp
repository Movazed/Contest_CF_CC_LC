#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(2);
        int index = 0;

        for(int i = 0; i < n; ++i){
            bool found = false;
            for(int j = 0; j < n; ++j){
                if (i != j && nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            if (!found){
                result[index++] = nums[i];
                if (index == 2) {
                    break;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 1, 3, 2, 5};
    std::vector<int> result = solution.singleNumber(nums);

    std::cout << "The two single numbers are: " << result[0] << " and " << result[1] << std::endl;

    return 0;
}
