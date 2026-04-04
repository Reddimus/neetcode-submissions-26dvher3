class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const unsigned int N = prices.size();
        std::vector<std::vector<int>> dp(N, {-1, -1});

        std::function<int(unsigned int, bool)> rec = [&](unsigned int i, bool bought) -> int {
            if (i == N)
                return 0;
            if (dp[i][bought] != -1)
                return dp[i][bought];

            int res = rec(i + 1, bought);
            dp[i][bought] = bought ?
                max(res, prices[i] + rec(i + 1, false)) :
                max(res, -prices[i] + rec(i + 1, true));
            return dp[i][bought];
        };
        return rec(0, false);
    }
};