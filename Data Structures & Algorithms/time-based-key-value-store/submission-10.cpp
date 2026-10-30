class TimeMap {
public:
    TimeMap() = default;
    
    void set(const string key, const string value, const int timestamp) {
        map_time[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        const auto& timestamped_values = map_time[key];

        // Binary search for the first entry with time > timestamp
        auto it = std::upper_bound(
            timestamped_values.begin(),
            timestamped_values.end(),
            make_pair(timestamp, std::string{CHAR_MAX})
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
