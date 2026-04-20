class Solution {
public:
    bool isValid(std::string& s) {
        const std::map<char, char> close_to_open = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        std::vector<char> stk;
        stk.reserve(s.size());
        for (const char c : s) {
            if (!close_to_open.contains(c)) // open parentheses
                stk.push_back(c);
            else if (stk.empty() || close_to_open.at(c) != stk.back())
                return false;
            else
                stk.pop_back();
        }
        return stk.empty();
    }
};
