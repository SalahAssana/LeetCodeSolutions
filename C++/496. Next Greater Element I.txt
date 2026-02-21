class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        stack = []
        next_greater = {}

        # Build next greater mapping for nums2
        for x in nums2:
            while stack and x > stack[-1]:
                next_greater[stack.pop()] = x
            stack.append(x)

        # Remaining elements have no next greater
        while stack:
            next_greater[stack.pop()] = -1

        # Answer queries from nums1
        return [next_greater[x] for x in nums1]