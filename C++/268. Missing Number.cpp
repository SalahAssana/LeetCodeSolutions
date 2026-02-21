class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        ans = 0
        
        # XOR all indices and numbers
        for i in range(n + 1):
            ans ^= i
        for x in nums:
            ans ^= x
        
        return ans