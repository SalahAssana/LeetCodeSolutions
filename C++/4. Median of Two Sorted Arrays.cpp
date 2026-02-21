class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // The first array must always be the smaller of the two.
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        
        int low = 0;
        int high = nums1_size;
        
        while (low <= high)
        {
            int partition1 = (low+high)/2;
            int partition2 = (nums1_size+nums2_size+1)/2 - partition1;
            
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1-1];
            int minRight1 = (partition1 == nums1_size) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2-1];
            int minRight2 = (partition2 == nums2_size) ? INT_MAX : nums2[partition2];
            
            // If the correct parition points are found we return the median
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((nums1_size + nums2_size) % 2 == 0)
                {
                    return ((double)max(maxLeft1, maxLeft2) + min(minRight1, minRight2))/2;
                }
                else
                {
                    return (double)max(maxLeft1, maxLeft2);
                }
            }
            // If the max value on the left of the parition in first array is greater than the
            // min value to the right of the parition in the second array we move the first parition.
            else if (maxLeft1 > minRight2)
            {
                high = --partition1;
            }
            // Else move the parition to the right.
            else
            {
                low = ++partition1;
            }
        }
        
        return 0.0;
    }
};