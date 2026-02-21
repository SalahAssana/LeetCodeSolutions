class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type nums2: List[int]
        :rtype: bool
        """
        last_index = {}

        for i, x in enumerate(nums):
            if x in last_index and i - last_index[x] <= k:
                return True
            last_index[x] = i

        return False