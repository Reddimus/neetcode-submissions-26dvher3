class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, UNCOMPUTED));
        std::function<int(int, bool)> recursive = [&](int i, bool bought) -> int {
            if (i == prices.size())
                return 0;
            
            if (dp[i][bought] != UNCOMPUTED)
                return dp[i][bought];
            
            int maximumProfit = recursive(i + 1, bought);
            if (bought)
                maximumProfit = std::max(prices[i] + recursive(i + 1, false), maximumProfit);
            else
                maximumProfit = std::max(-prices[i] + recursive(i + 1, true), maximumProfit);
            dp[i][bought] = maximumProfit;
            return maximumProfit;
        };
        return recursive(0, false);
    }
private:
    static constexpr int UNCOMPUTED = -1;
};