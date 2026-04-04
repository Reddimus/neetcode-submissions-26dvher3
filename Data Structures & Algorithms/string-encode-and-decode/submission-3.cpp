class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string s : strs) {
            encoded.push_back(s.size());
            encoded += s;
        }
        cout << encoded << endl;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            decoded.push_back(s.substr(i + 1, s[i]));
            i += 1 + s[i];
        }
        return decoded;
    }
};
