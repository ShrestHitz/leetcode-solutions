
class Solution {
public:
    int BS(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;
        int index = 0;

        // Step 1: Find the index of the minimum element
        while (start <= end) {
            if (nums[start] <= nums[end]) {
                index = start;
                break;
            }

            int mid = start + (end - start) / 2;
            int next = (mid + 1) % size;
            int prev = (mid + size - 1) % size;

            if (nums[mid] <= nums[next] &&
                nums[mid] <= nums[prev]) {
                index = mid;
                break;
            }

            if (nums[start] <= nums[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // Step 2: Binary search in the first half
        int result = BS(nums, 0, index - 1, target);

        if (result != -1) {
            return result;
        }

        // Step 3: Binary search in the second half
        return BS(nums, index, size - 1, target);
    }
};