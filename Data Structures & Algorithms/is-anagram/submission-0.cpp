class Solution {
public:
    bool isAnagram(string s, string t) {
        char charCount[26] = {0}; 
        for (char c : s)
            charCount[c - 'a']++;
        for (char c : t)
            charCount[c - 'a']--;
        for (std::uint8_t i = 0; i < 26; ++i)
            if (charCount[i])
                return false;
        return true;
    }
};
