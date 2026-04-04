class Solution {
public:
    bool isSubsequence(string s, string t) {
        std::uint16_t si = 0;
        for(std::uint16_t ti = 0; si < s.size() && ti < t.size(); ++ti) 
            if (s[si] == t[ti])
                si++;
        return si == s.size();
    }
};