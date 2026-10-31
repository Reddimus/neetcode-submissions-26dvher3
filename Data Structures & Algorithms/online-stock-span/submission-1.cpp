class StockSpanner {
public:
    StockSpanner() {
        prices.reserve(EXPECTED_CALLS);
    }
    
    int next(int price) {
        prices.push_back(price);

        int i = prices.size() - 2;
        while (i >= 0 && prices[i] <= price)
            --i;
        return prices.size() - 1 - i;
    }
private:
    static constexpr std::size_t EXPECTED_CALLS = 100001;
    std::vector<int> prices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */