class StockSpanner {
public:
    StockSpanner() {
        price_spans.reserve(POSSIBLE_CALLS);
    }
    
    int next(int price) {
        int span = 1;

        for (int i = price_spans.size() - 1;
            i >= 0 && price_spans[i].first <= price;
            span += price_spans[i].second, i -= price_spans[i].second);

        price_spans.emplace_back(price, span);
        return span;
    }
private:
    static constexpr std::size_t POSSIBLE_CALLS = 100001;
    std::vector<std::pair<int, int>> price_spans;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */