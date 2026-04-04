class Solution {
public:
    // T: O(n * L), M: O(n * L)
    // n is the # of elements in strs
    // L is the maximum length of an individual string
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagram_groups;
        for (const std::string& s : strs) 
            anagram_groups[get_stringified_char_count(s)].push_back(s);

        std::vector<std::vector<std::string>> grouped_anagrams;
        grouped_anagrams.reserve(anagram_groups.size());
        for (const auto& [_, group] : anagram_groups)
            grouped_anagrams.push_back(group);        
        return grouped_anagrams;
    }

private:
    // T: O(L), M: O(L)
    const std::string get_stringified_char_count(const std::string& s) {
        std::string char_count(26, 0);
        for (char c : s)
            char_count[c - 'a']++;
        return char_count;
    }
};
