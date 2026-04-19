class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> stk;
        stk.reserve(operations.size());
        for (const std::string& op : operations) {
            if (op == "+" && stk.size() > 1)
                stk.push_back(stk[stk.size() - 1] + stk[stk.size() - 2]);
            else if (op == "D" && stk.size())
                stk.push_back(stk.back() * 2);
            else if (op == "C" && stk.size())
                stk.pop_back();
            else [[likely]] 
                stk.push_back(std::stoi(op));
        }
        return std::accumulate(stk.begin(), stk.end(), 0);
    }
};