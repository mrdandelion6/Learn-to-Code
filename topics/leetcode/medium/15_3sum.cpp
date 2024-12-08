#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end()); // sort list first
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) // skip over duplicate values 
                continue;
            if (nums[i] > 0) // can't make any more zero sums 
                return sol;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int three_sum = nums[i] + nums[l] + nums[r];
                if (three_sum == 0) { // found a solution
                    sol.push_back({nums[i], nums[l], nums[r]});
                    l ++;
                    while (nums[l] == nums[l-1] && l < r)
                        l ++;
                }
                else if (three_sum > 0) // need smaller values
                    r--;
                else
                    l++;
            }
        }
        return sol;
    }
};