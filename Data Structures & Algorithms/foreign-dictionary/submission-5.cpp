class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, bitset<26>> adjList;
        for (const string& w : words)
            for (const char& c : w)
                adjList[c];

        for (int i = 0; i < words.size() - 1; ++i) {
            const string &w1 = words[i], &w2 = words[i+1];
            const int minLength = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0, minLength) == w2.substr(0, minLength))
                return "";
            for (int ci = 0; ci < minLength; ++ci) {
                if (w1[ci] == w2[ci])
                    continue;
                
                adjList[w1[ci]][w2[ci] - 'a'] = true;
                break;
            }
        }

        string topOrder = "";
        char visited[26] = {};
        function<bool(char)> dfs = [&](char c) -> bool {
            if (visited[c - 'a'] == 'v')
                return true;
            if (visited[c - 'a'] == 'c')
                return false;

            visited[c - 'a'] = 'c';

            for (const auto& [ac, adjChars] : adjList)
                if (adjList[c][ac - 'a'] && !dfs(ac))
                    return false;

            topOrder += c;
            visited[c - 'a'] = 'v';
            return true;
        };

        for (const auto& [c, adjChars] : adjList)
            if (!dfs(c))
                return "";
        reverse(topOrder.begin(), topOrder.end());
        return topOrder;
    }
};
