#include <array>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Use std::array. It lives on the stack (fast) and has .begin() (elegant).
        // We use int16_t because count <= 10^4 fits easily in 16 bits.
        std::array<int16_t, MAX_UNIQUE_NUMS> numsCount = {0};

        for (int num : nums) {
            numsCount[num + OFFSET]++;
        }

        // Now .begin() and .end() are valid
        const auto MAX_COUNT = *std::max_element(numsCount.begin(), numsCount.end());

        // 2. Buckets
        std::vector<std::vector<int16_t>> countNums(MAX_COUNT + 1);
        
        // FIX: Iterate the full range of unique numbers (0..2000), not just up to count.
        for (std::uint16_t i = 0; i < MAX_UNIQUE_NUMS; ++i) {
            if (numsCount[i] > 0) {
                countNums[numsCount[i]].push_back(i - OFFSET);
            }
        }

        // 3. Result
        // Using reserve + push_back is generally preferred over pre-initialization
        // because it avoids default-constructing k integers (looping twice).
        std::vector<int> topK;
        topK.reserve(k);

        for (int i = MAX_COUNT; i > 0 && topK.size() < k; --i) {
            for (int16_t num : countNums[i]) {
                topK.push_back(num);
                if (topK.size() == k) return topK;
            }
        }
        return topK;
    }

private:
    // static constexpr is the modern C++ standard for class constants
    static constexpr int MAX_UNIQUE_NUMS = 2001;
    static constexpr int OFFSET = 1000;
};