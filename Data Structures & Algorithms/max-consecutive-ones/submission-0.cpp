class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, currCount = 0;
        for (int num : nums) {
            if (num == 1) {
                currCount++;
                maxCount = std::max(maxCount, currCount);
            } else {
                currCount = 0;
            }
        }
        return maxCount;
    }
};