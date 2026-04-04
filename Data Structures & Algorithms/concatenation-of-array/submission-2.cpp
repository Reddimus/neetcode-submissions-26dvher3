class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const std::size_t original_size = nums.size();
        nums.resize(original_size * 2);
        for (std::size_t i = 0; i < original_size; ++i)
            nums[original_size + i] = nums[i];
        return nums;
    }
};