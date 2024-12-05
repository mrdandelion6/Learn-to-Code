#include <vector>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            /* want O(log(n))*/
            int l = 0;
            int r = nums.size() - 1;
            int m = (r - l) / 2; 

            // quick checks 
            if (nums[l] == target)
                return l;
            if (nums[m] == target)
                return m;
            if (nums[r] == target)
                return r;

            

            return -1;
        }

};