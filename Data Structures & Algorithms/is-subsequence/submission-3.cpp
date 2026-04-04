class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 1. Map t chars -> {indices}
        std::queue<std::uint16_t> tIndices[26];
        for (std::uint16_t i = 0; i < t.size(); ++i)
            tIndices[t[i] - 'a'].push(i);

        int ti = -1; // Keep track of the last index we used in t
        for (char c : s) {
            std::queue<std::uint16_t>& tq = tIndices[c - 'a'];

            while (!tq.empty() && tq.front() <= ti)
                tq.pop();

            if (tq.empty())
                return false; 
            
            ti = tq.front();
            tq.pop();
        }
        return true;
    }
};