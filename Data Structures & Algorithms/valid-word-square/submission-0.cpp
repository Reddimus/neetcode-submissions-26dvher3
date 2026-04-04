class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        const std::size_t ROWS = words.size();
        
        for (std::size_t r = 0; r < ROWS; ++r) 
            for (std::size_t c = 0; c < words[r].size(); ++c) 
                if (c >= ROWS ||
                    r >= words[c].length() ||
                    words[r][c] != words[c][r]) 
                    return false;
        return true;
    }
};