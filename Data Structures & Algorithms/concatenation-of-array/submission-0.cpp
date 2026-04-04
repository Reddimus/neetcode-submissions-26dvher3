class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const int ORIGINAL_SIZE = nums.size();
        nums.resize(ORIGINAL_SIZE * 2);
        for (int i = 0; i < ORIGINAL_SIZE; ++i)
            nums[ORIGINAL_SIZE + i] = nums[i];
        return nums;
    }
};