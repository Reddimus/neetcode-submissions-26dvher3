class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const unsigned int N = prices.size();
        std::vector<std::vector<int>> dp(N, std::vector<int>(2, -1));

        std::function<int(unsigned int, int)> rec = [&](unsigned int i, int bought) -> int {
            if (i == prices.size())
                return 0;
            if (dp[i][bought] != -1)
                return dp[i][bought];

            int res = rec(i + 1, bought);
            res = bought == 1 ?
                max(res, prices[i] + rec(i + 1, 0)) :
                max(res, -prices[i] + rec(i + 1, 1));
            dp[i][bought] = res;
            return res;
        };
        return rec(0, 0);
    }
};