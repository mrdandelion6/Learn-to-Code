from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        d = {} # hashmap for O(1) lookup

        for num in nums:
            if num in d:
                return True
            d[num] = 1

        return False
    

# O(n) solution. this problem is easily solved using a hashmap in python.
# alternatively, you can take a look at the C++ solution.