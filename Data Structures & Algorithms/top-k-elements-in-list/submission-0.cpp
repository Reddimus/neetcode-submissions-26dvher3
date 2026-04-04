class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, std::size_t> numsCount;
        numsCount.reserve(
            std::min(nums.size() + 1, MAX_UNIQUE_NUMS));
        for (int num : nums)
            numsCount[num]++;

        const std::size_t MAX_COUNT = std::max_element(
            numsCount.begin(),
            numsCount.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }
        )->second;

        std::vector<std::vector<int>> countNums(MAX_COUNT + 1);
        for (const auto& [num, count] : numsCount)
            countNums[count].push_back(num);

        std::vector<int> topK;
        topK.reserve(k);
        for (int i = MAX_COUNT; i > 0; --i) {
            for (int num : countNums[i]) {
                if (topK.size() == k)
                    return topK;

                topK.push_back(num);
            }
        }
        return topK;
    }
private:
    constexpr static std::size_t MAX_UNIQUE_NUMS = 2001;
};
