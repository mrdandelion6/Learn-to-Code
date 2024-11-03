from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        cheapest_cost = prices[0]

        for price in prices:
            if price < cheapest_cost:
                cheapest_cost = price
            if price - cheapest_cost > max_profit:
                max_profit = price - cheapest_cost

        return max_profit
    

# for this problem we have an O(n) solution.
# the main thing to remember is that we can only sell stock in the future
# so all we need to do is keep track of the lowest price we have seen
# and the greatest difference we will find.