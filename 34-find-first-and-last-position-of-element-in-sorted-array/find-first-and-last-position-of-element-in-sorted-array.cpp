class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // Find first occurrence
        int start = 0;
        int end = nums.size() - 1;
        int res1 = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target == nums[mid]) {
                res1 = mid;
                end = mid - 1;       // move left for first occurrence
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        // Find last occurrence
        start = 0;
        end = nums.size() - 1;
        int res2 = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target == nums[mid]) {
                res2 = mid;
                start = mid + 1;     // move right for last occurrence
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return {res1, res2};
    }
};