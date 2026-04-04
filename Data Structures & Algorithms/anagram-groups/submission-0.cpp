class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string, vector<string>> anagramGroups;
        for (string& str : strs)
            anagramGroups[getStringifiedAlphabetCount(str)].push_back(str); 
        
        std::vector<std::vector<std::string>> groupedAnagrams;
        groupedAnagrams.reserve(anagramGroups.size());
        for (const auto& [_, groups] : anagramGroups)
            groupedAnagrams.push_back(groups);
        return groupedAnagrams;
    }
private:
    std::string getStringifiedAlphabetCount(std::string& s) {
        std::string alphabetCount(26, 0);
        for (char c : s)
            alphabetCount[c - 'a']++;
        return alphabetCount;
    }
};
