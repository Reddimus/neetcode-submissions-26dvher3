class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentNotHolding = 0, nextNotHolding = 0;
        int currentHolding = 0, nextHolding = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            currentNotHolding = std::max(   // Compare
                -prices[i] + nextHolding,   // Buying today
                nextNotHolding);            // vs doing nothing
            currentHolding = std::max(      // Compare
                prices[i] + nextNotHolding, // Selling today
                nextHolding);               // vs doing nothing
            // Update next/old values
            nextNotHolding = currentNotHolding;
            nextHolding = currentHolding;
        }
        return currentNotHolding;
    }
};