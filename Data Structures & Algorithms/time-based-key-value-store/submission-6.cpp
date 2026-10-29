class TimeMap {
public:
    TimeMap() = default;
    
    void set(const string key, const string value, const int timestamp) {
        map_time[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        const std::vector<std::pair<int, std::string>>& timestamped_values = map_time[key];
        int left = 0, right = timestamped_values.size() - 1;
        std::string value = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (timestamped_values[mid].first <= timestamp) {
                value = timestamped_values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return value;
    }

private:
    std::unordered_map<
        std::string,
        std::vector<std::pair<int, std::string>>
    > map_time;
};
