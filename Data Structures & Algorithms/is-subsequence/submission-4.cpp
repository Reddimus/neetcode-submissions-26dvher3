class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Map t chars -> {indices}
        std::queue<std::int16_t> tIndices[26];
        for (std::int16_t i = 0; i < t.size(); ++i)
            tIndices[t[i] - 'a'].push(i);

        // Keep track of the last index we used in t
        std::int16_t ti = -1;
        for (char c : s) {
            std::queue<std::int16_t>& tq = tIndices[c - 'a'];

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