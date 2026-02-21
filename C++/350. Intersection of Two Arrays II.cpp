class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        from collections import Counter

        c1 = Counter(nums1)
        c2 = Counter(nums2)

        res = []
        for num in c1:
            if num in c2:
                res.extend([num] * min(c1[num], c2[num]))

        return res