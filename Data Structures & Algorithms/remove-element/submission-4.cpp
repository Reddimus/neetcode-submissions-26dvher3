class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int remove_count = 0;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[r] == val) {
                r--;
                remove_count++;
                continue;
            }

            if (nums[l] == val) {
                std::swap(nums[l], nums[r]);
                l++, r--;
                remove_count++;
            } else {
                l++;
            }
        }
        return nums.size() - remove_count;
    }
};