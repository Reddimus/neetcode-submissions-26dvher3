class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<std::size_t> char_count(ALPHABET_COUNT, 0);

        for (char c : s)
            char_count[c - 'a']++;

        for (char c : t)
            char_count[c - 'a']--;

        for (const std::size_t count : char_count)
            if (count != 0)
                return false;
        return true;
    }
private:
    static constexpr std::uint8_t ALPHABET_COUNT = 26;
};
