class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, UNCOMPUTED));
        std::function<int(std::size_t, bool)> topDown = [&](std::size_t i, bool bought) -> int {
            if (i == prices.size())
                return 0;
            
            if (dp[i][bought] != UNCOMPUTED)
                return dp[i][bought];
            // Calculate option A: Do nothing today
            int maximumProfit = topDown(i + 1, bought);
            // Compare option A against option B: Act today
            maximumProfit = bought ?
                std::max(prices[i] + topDown(i + 1, false), maximumProfit) :    // compare selling today
                std::max(-prices[i] + topDown(i + 1, true), maximumProfit);     // compare buying today
            // dp[i][bool] is dependent on dp[i + 1][!bool]
            dp[i][bought] = maximumProfit;
            return maximumProfit;
        };
        return topDown(0, false);
    }
private:
    static constexpr int UNCOMPUTED = -1;
};