class TimeMap {
public:
    TimeMap() {
        map_time.reserve(POSSIBLE_CALLS);
    }
    
    void set(string key, string value, int timestamp) {
        map_time[key].emplace_back(timestamp, value);
    }
    
    string get(const string key, const int timestamp) {
        if (map_time.find(key) == map_time.end())
            return "";

        const std::vector<std::pair<int, std::string>>& timed_values = map_time[key];

        const auto it = std::upper_bound(
            timed_values.begin(),
            timed_values.end(),
            timestamp,
            [](const int target, const std::pair<int, std::string>& element) {
                return target < element.first;
            }
        );

        return it == timed_values.begin() ? "" : std::prev(it)->second;
    }
private:
    static constexpr std::size_t POSSIBLE_CALLS = 2 * 1e5 + 1;
    std::unordered_map<
        std::string,
        std::vector<std::pair<int, std::string>>
    > map_time;
};
