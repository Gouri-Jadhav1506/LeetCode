class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Check which side is sorted
            if (nums[left] <= nums[mid]) { 
                // Left side is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // target in left part
                } else {
                    left = mid + 1;   // target in right part
                }
            } else { 
                // Right side is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // target in right part
                } else {
                    right = mid - 1;  // target in left part
                }
            }
        }
        return -1;
    }
};
