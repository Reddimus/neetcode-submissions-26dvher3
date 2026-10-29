class TimeMap {
public:
    TimeMap() = default;
    
    void set(const string key, const string value, const int timestamp) {
        map_time[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto it_key = map_time.find(key);
        if (it_key == map_time.end())
            return "";
        
        const auto& timestamped_values = it_key->second;

        // Custom comparator comparing int timestamp with pair<int, string>
        auto it = std::upper_bound(
            timestamped_values.begin(), timestamped_values.end(), timestamp,
            [](int target, const std::pair<int, std::string>& element) {
                return target < element.first;
            }
        );

        // If iterator point to begin(), all timestamps are > target
        return it == timestamped_values.begin() ? "" : std::prev(it)->second;
    }

private:
    std::unordered_map<
        std::string,
        std::vector<std::pair<int, std::string>>
    > map_time;
};
