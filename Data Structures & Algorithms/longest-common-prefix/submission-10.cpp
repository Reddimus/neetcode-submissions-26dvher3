#include <array>

#define ALPHABET_SIZE 26

struct TrieNode {
    std::array<TrieNode*, ALPHABET_SIZE> children = {nullptr};
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            
            node = node->children[c - 'a'];
        }
    }

    std::size_t getCommonPrefixLength(const std::string& word, const std::size_t limit) {
        const std::size_t MAX_PREFIX_LEN = std::min(limit, word.length()); 

        TrieNode* node = root;
        std::size_t i = 0;
        while (i < MAX_PREFIX_LEN) {
            if (!node->children[word[i] - 'a'])
                break;

            node = node->children[word[i] - 'a'];
            ++i;
        }
        return i;
    } 
private:
    TrieNode* root;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::size_t shortestIndex = 0;
        for (std::size_t i = 1; i < strs.size(); ++i)
            if (strs[i].length() < strs[shortestIndex].length())
                shortestIndex = i;

        Trie trie;
        trie.insert(strs[shortestIndex]);

        std::size_t lcpLength = strs[shortestIndex].length();
        for (const std::string& s : strs) 
            lcpLength = trie.getCommonPrefixLength(s, lcpLength);
        return strs[shortestIndex].substr(0, lcpLength);
    }
};