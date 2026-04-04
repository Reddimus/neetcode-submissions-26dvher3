class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char sToT[UINT8_MAX] = {0};
        char tToS[UINT8_MAX] = {0};
        for (std::size_t i = 0; i < s.size(); ++i) {
            // If already maped and doesnt match passed map
            if ((sToT[s[i]] && sToT[s[i]] != t[i]) ||
            (tToS[t[i]] && tToS[t[i]] != s[i]))
                return false;   // Is not isomorphic

            sToT[s[i]] = t[i];
            tToS[t[i]] = s[i];
        }
        return true;
    }
};
