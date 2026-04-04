class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::uint8_t l = 0, r = nums.size();
        while (l < r) {
            if (nums[l] == val)
                swap(nums[l], nums[--r]);
            else
                ++l;
        }
        return r; 
    }
};