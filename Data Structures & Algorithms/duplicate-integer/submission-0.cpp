class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end())
                return true;
            seen.insert(num);
        }
        return false;
    }
};