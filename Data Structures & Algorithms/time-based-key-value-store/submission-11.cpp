class TimeMap {
public:
    TimeMap() = default;
    
    void set(const string key, const string value, const int timestamp) {
        map_time[key].emplace_back(timestamp, value);
    }
    
    string get(const string key, const int timestamp) {
        const auto& timestamped_values = map_time[key];

        // Binary search for the first entry with time > timestamp
        const auto it = std::upper_bound(
            timestamped_values.begin(),
            timestamped_values.end(),
            timestamp,
            [](const int target, const std::pair<int, std::string>& element) {
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
