class Solution {
public:
    // T: O(n log k) = O(s log k) = O(n log 26) = O(n)
    // M: O(k) = O(26) = O(1)
    // Where n is length of s and k is number of distinct characters (k <= 26)
    string reorganizeString(string s) {
        int16_t char_count[26] = {0};
        for (char c : s)
            char_count[c - 'a']++;

        std::priority_queue<std::pair<std::int16_t, char>> pq;
        for (std::uint8_t ci = 0; ci < 26; ++ci)
            if (char_count[ci])
                pq.push({char_count[ci], ci + 'a'});
        
        if (pq.top().first > static_cast<std::int16_t>(s.size() + 1) / 2)
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
                // Get character with 2nd most frequency
                auto [count, c] = pq.top();
                pq.pop(); 

                pq.push(prev); // Re-queue previously saved character

                // Use character with 2nd most frequency & update previously used character
                s.push_back(c);
                if (--count) {
                    prev = {count, c};
                    pq.push(prev);
                } else {
                    prev = {0, 0};
                }
                continue;
            }

            // Use character with most frequency & update previously used character
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