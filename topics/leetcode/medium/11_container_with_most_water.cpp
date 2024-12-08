#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int area = (j - i) * min(height[j], height[i]);
            if (area > max_area)
                max_area = area;
            if (height[j] > height[i])
                i++;
            else
                j--;
        }
        return max_area;
    }
};
