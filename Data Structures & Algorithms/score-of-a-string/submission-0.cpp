class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for (std::uint8_t i = 0; i < s.size() - 1; ++i) 
            score += std::abs(s[i] - s[i + 1]);
        return score;
    }
};