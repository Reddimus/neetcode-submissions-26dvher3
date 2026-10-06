class Solution {
public:
    string reorganizeString(string s) {
        int16_t char_count[26] = {0};
        for (char c : s)
            char_count[c - 'a']++;

        std::priority_queue<std::pair<std::int16_t, char>> pq;
        for (std::uint8_t ci = 0; ci < 26; ++ci)
            if (char_count[ci])
                pq.push({char_count[ci], ci + 'a'});
        
        const std::int16_t original_size = s.size();
        if (pq.top().first > (original_size + 1) / 2)
            return "";
        
        std::pair<std::int16_t, char> prev = {0, 0};
        s.clear();
        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();

            // If previous character is a duplicate
            if (prev.second == c) {
                prev = {count, c};  // Save character for next placement
                if (pq.empty())
                    return "";
                // Use character with 2nd most frequency
                auto [count, c] = pq.top();
                pq.pop(); 

                pq.push(prev); // Re-queue previously saved character

                s.push_back(c);
                if (--count) {
                    prev = {count, c};
                    pq.push(prev);
                } else {
                    prev = {0, 0};
                }
                continue;
            }

            s.push_back(c);
            if (--count) {
                prev = {count, c};
                pq.push(prev);
            } else {
                prev = {0, 0};
            }
        }

        return s;
    }
};