#include <array>

struct TrieNode {
    std::array<TrieNode*, INT8_MAX> children{};
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c])
                node->children[c] = new TrieNode();
            
            node = node->children[c];
        }
    }

    std::size_t lcp(const string& word, std::size_t prefixLength) {
        TrieNode* node = root;
        for (std::size_t i = 0; i < min(word.length(), prefixLength); ++i) {
            if (!node->children[word[i]])
                return i; // We found a mismatch, return current length i
            
            node = node->children[word[i]];
        }
        // The word was a prefix, return the length we checked
        return min(word.length(), prefixLength);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::size_t shortestIndex = 0;
        for (std::size_t i = 1; i < strs.size(); ++i)
            if (strs[i].size() < strs[shortestIndex].size())
                shortestIndex = i;

        Trie trie;
        trie.insert(strs[shortestIndex]);
        
        std::size_t prefixLength = strs[shortestIndex].length();
        for (std::size_t i = 0; i < strs.size(); ++i)
            prefixLength = trie.lcp(strs[i], prefixLength);

        return strs[shortestIndex].substr(0, prefixLength);
    }
};