class StockSpanner {
public:
    StockSpanner() {
        price_spans.reserve(POSSIBLE_CALLS);
    }
    
    int next(int price) {
        int span = 1;
        while (!price_spans.empty() && price_spans.back().first <= price) {
            span += price_spans.back().second;
            price_spans.pop_back();
        }
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