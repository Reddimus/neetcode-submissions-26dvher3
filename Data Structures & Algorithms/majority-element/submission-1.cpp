class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int digit = nums.front();
        std::uint16_t count = 0;
        for (int num : nums) {
            if (count == 0)
                digit = num;
            
            count += num == digit ? 1 : -1;
        }
        return digit;
    }
};