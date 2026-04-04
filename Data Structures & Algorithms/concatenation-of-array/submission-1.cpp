class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const std::uint16_t ORIGINAL_SIZE = nums.size();
        nums.reserve(ORIGINAL_SIZE * 2);
        for (std::uint16_t i = 0; i < ORIGINAL_SIZE; ++i) 
            nums.push_back(nums[i]);
        return nums;
    }
};