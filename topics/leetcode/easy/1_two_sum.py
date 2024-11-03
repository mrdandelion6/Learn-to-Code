from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # we keep a hashmap of compliments
        d = {}

        for i, x in enumerate(nums):
            c = target - x
            # note that x + c = target, so c is the next value we will be looking for
            if c in d:
                return [d[c], i] # d[c] stores the index where we found the value c
            else:
                d[x] = i # if x turns out to be the compliment to another value in the future, we got our pair

# the above is an O(n) solution.
# a very elegant solution. it might be a little confusing at first.
# take your time to understand the if-else part of the code. that is where everything happens.
