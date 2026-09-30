class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        int mid = 0;

        while(left <= right) {
            mid = left + (right-left)/2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else break;
        }

        if (left > right) return {-1, -1};
        int found = mid;

        left = 0, right = found;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (nums[mid] != target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int first = left;

        left = found, right = n-1;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (nums[mid] != target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int last = right;

        return {first, last};
    }
};
