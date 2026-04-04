class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const std::size_t N = s.size();
        const std::size_t OPTIMAL_MAP_SIZE = N < UINT8_MAX ? N : UINT8_MAX;

        std::unordered_map<char, char> sToT(OPTIMAL_MAP_SIZE);
        std::unordered_map<char, char> tToS(OPTIMAL_MAP_SIZE);

        for (std::size_t i = 0; i < N; ++i) {
            // If already maped and doesnt match passed map
            if ((sToT.find(s[i]) != sToT.end() || tToS.find(t[i]) != tToS.end()) &&
            (sToT[s[i]] != t[i] || tToS[t[i]] != s[i]))
                return false;   // Is not isomorphic
            
            sToT[s[i]] = t[i];
            tToS[t[i]] = s[i];
        }
        return true;
    }
};
