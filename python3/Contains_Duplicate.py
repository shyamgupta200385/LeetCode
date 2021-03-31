/*
Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4]
Output: false
*/

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        index = set(nums)
        if len(nums) > len(index):
            return True
        else:
            return False
