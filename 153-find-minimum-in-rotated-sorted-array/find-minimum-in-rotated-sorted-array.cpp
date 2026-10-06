class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int start = 0;
        int end = N - 1;

        while (start <= end) {
            // Array is already sorted
            if (nums[start] <= nums[end]) {
                return nums[start];
            }

            int mid = start + (end - start) / 2;

            int next = (mid + 1) % N;
            int prev = (mid + N - 1) % N;

            // mid is the minimum
            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
                return nums[mid];
            }

            // Left half is sorted
            if (nums[start] <= nums[mid]) {
                start = mid + 1;
            }
            // Right half is sorted
            else {
                end = mid - 1;
            }
        }

        return -1;
    }
};