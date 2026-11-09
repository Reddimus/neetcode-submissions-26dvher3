class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // tabulation table: dp[i] = {int notHolding, int holding}
        std::vector<std::pair<int, int>> dp(prices.size() + 1);

        for (int i = prices.size() - 1; i >= 0; --i) {
            dp[i].first = std::max(             // Compare
                -prices[i] + dp[i + 1].second,  // Purchasing today 
                dp[i + 1].first);               // vs doing nothing
            dp[i].second = std::max(            // Compare
                prices[i] + dp[i + 1].first,    // Selling today
                dp[i + 1].second);              // vs doing nothing
        }
        return dp[0].first;
    }
};