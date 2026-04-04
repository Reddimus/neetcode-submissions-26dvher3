class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<vector<int>> triangle(numRows);
        triangle[0] = {1};

        for (std::int8_t r = 1; r < numRows; ++r) {
            triangle[r] = std::vector<int>(triangle[r - 1].size() + 1, 1);
            for (std::int8_t c = 1; c < triangle[r].size() - 1; ++c)
                triangle[r][c] = triangle[r - 1][c - 1] + triangle[r - 1][c];
        }

        return triangle;
    }
};