class Solution {
public:
void moveZeroes(vector<int>& nums) {
    int insertPos = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            // Only swap when the element isn't already in position
            if (i != insertPos) {
                nums[insertPos] = nums[i];
                nums[i] = 0;
            }
            insertPos++;
        }
    }
}
};