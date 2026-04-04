class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (string& s : strs) {
            encoded.push_back(char(s.size()));
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            const int sSize = int(s[i]);
            decoded.push_back(s.substr(i + 1, sSize));
            i += sSize + 1;
        }
        return decoded;
    }
};
