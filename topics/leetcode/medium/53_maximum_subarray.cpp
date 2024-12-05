#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int max_val = nums[0];
            int running_sum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                running_sum = max(nums[i], running_sum + nums[i]);
                if (running_sum > max_val)
                    max_val = running_sum;
            }
            return max_val;
        }
};