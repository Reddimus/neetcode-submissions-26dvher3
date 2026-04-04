class Solution {
public:
    // T: O(n + k log n), M: O(n)
    // n is the size of nums
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, std::uint16_t> num_count; 
        num_count.reserve(2001);
        for (const int num : nums)
            num_count[num]++;
    
        std::vector<std::pair<std::uint16_t, int>> hq; // max heap-queue
        hq.reserve(num_count.size());
        for (const auto& [num, count] : num_count)
            hq.push_back({count, num});
        
        std::make_heap(hq.begin(), hq.end()); // O(n)
        
        std::vector<int> top_k(k);
        for (std::uint16_t i = 0; i < k; ++i) {
            top_k[i] = hq.front().second;
            std::pop_heap(hq.begin(), hq.end());
            hq.pop_back();
        }
        return top_k;
    }
};
