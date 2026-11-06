class Solution {
public:
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    int insertPos = 0;

    // Collect non-zero elements
    for (int num : nums) {
        if (num != 0) {
            result[insertPos] = num;
            insertPos++;
        }
    }

    // Copy result back into nums
    for (int i = 0; i < n; i++) {
        nums[i] = result[i];
    }
}
};