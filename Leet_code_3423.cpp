#include<bits/stdc++.h>
using namespace std;
#define ll long long            
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        ll n = nums.size();
        ll max_diff = 0;
        for(ll i = 0; i < nums.size(); i++){
            ll diff = abs(nums[i] - nums[(i + 1) % n]);
            max_diff = max(max_diff, diff);
        }
        return max_diff;

    }
};