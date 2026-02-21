class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_ones = 0
        curr = 0

        for x in nums:
            if x == 1:
                curr += 1
                if curr > max_ones:
                    max_ones = curr
            else:
                curr = 0

        return max_ones