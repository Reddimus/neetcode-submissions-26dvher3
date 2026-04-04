class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, std::uint16_t> num_count; 
        num_count.reserve(2001);
        for (const int& num : nums)
            num_count[num]++;
    
        std::priority_queue<
            std::pair<std::uint16_t, int>,
            std::vector<std::pair<std::uint16_t, int>>,
            std::greater<std::pair<std::uint16_t, int>>> pq; // min
        for (const auto& [num, count] : num_count)
            pq.push({count, num});
        
        while (!pq.empty() && pq.size() > k)
            pq.pop();
        
        std::vector<int> top_k(k);
        for (std::uint16_t i = 0; !pq.empty() && i < k; ++i) {
            top_k[i] = pq.top().second;
            pq.pop();
        }
        return top_k;
    }
};
