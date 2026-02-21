class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)

        # Mark numbers as visited
        for i in range(n):
            idx = abs(nums[i]) - 1
            if nums[idx] > 0:
                nums[idx] = -nums[idx]

        # Collect missing numbers
        res = []
        for i in range(n):
            if nums[i] > 0:
                res.append(i + 1)

        return res