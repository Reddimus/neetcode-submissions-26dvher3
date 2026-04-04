class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::uint8_t k = 0;
        for (std::uint8_t i = 0; i < nums.size(); ++i)
            if (nums[i] != val)
                nums[k++] = nums[i];
        return k;
    }
};