class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (const int& num : nums) {
            if (seen.find(num) != seen.end())
                return true;
            seen.insert(num);
        }
        return false;
    }
};