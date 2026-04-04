class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int digit = nums[0], count = 0;
        for (int num : nums) {
            if (count == 0)
                digit = num;
            count += digit == num ? 1 : -1;
        }
        return digit;
    }
};