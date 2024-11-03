from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (right + left) // 2
            
            if nums[mid] > nums[right]:
                # minimum is in right half
                left = mid + 1
            elif nums[mid] < nums[right]:
                # minimum is in left half (including mid)
                right = mid
            else:
                # nums[mid] == nums[right]
                # can't determine which half, but we know nums[right]
                # isn't the unique minimum since we have a copy at mid
                right -= 1
                
        return nums[right]
    
# remarks:
# note that we used a binary search approach.
# however, when nums[mid] == nums[right], we actually have no way of knowing
# whether to search in the left half or the right half.
# for example, consider [3,...1,...,(3),...,3]
# where (3) is the middle element (value of 3). 
# we use ... to denote a very large number of 3's repeating.
# in this case, we can intuitively see there really is no way of knowing whether
# to go left or to go right.
# we will just have to shrink the array one element at a time, giving a worst case
# time complexity of O(n).
