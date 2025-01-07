#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int longestPalindrome(const std::string& s) {
        std::unordered_set<char> charSet;
        int length = 0;
        for (char c : s) {
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                length += 2;
            } else {
                charSet.insert(c);
            }
        }
        if (!charSet.empty()) {
            length += 1;
        }
        return length;
    }
};

int main() {
    Solution solution;
    
    // Test case
    std::string s = "abccccdd";
    int result = solution.longestPalindrome(s);
    
    std::cout << "The length of the longest palindrome that can be built is: " << result << std::endl;
    
    return 0;
}
