class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const std::uint8_t MIN_LEN = getMinLength(strs);

        string longestPrefix;
        longestPrefix.reserve(MIN_LEN);
        for (std::uint8_t i = 0; i < MIN_LEN; ++i) {
            char currChar = strs[0][i];
            for (const string& s : strs) 
                if (currChar != s[i])
                    return longestPrefix;
            longestPrefix.push_back(currChar);
        }
        return longestPrefix;
    }
private:
    const std::uint8_t getMinLength(vector<string>& strs) {
        std::uint8_t length = UINT8_MAX;
        for (const string& s : strs)
            length = min(length, static_cast<std::uint8_t>(s.size()));
        return length;
    }
};