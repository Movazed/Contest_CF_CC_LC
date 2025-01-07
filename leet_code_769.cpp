#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> s= arr;
        sort(s.begin(), s.end());
        int c = 0, ind =-1;
        for(int i = 0; i < arr.size(); i++){
            ind = max(ind, int(find(s.begin(), s.end(), arr[i]) - s.begin()));
            if(ind == i){
                c++;
            }
        }
        return c;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Max chunks to make sorted: " << sol.maxChunksToSorted(arr) << endl;
    return 0;
}