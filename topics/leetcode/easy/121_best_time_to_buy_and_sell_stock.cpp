#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit = 0;
            int least = prices[0];
            for (int i = 0; i < prices.size(); i++) {
                if (prices[i] < least)
                    least = prices[i];
                if ((prices[i] - least) > max_profit)
                    max_profit = prices[i] - least;
            }
            return max_profit;
        }
};