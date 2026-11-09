class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N = nums.size();
        std::make_heap(nums.begin(), nums.end(), std::greater<int>());
        for (int i = 0; i < N; ++i) {
            if (nums.front() != i)
                return i;
            
            std::pop_heap(nums.begin(), nums.end() - i, std::greater<int>());
        }
        return N;
    }
};
