class TimeMap {
public:
    TimeMap() {
    }
    
    void set(const string key, const string value, const int timestamp) {
        map_time[key][timestamp] = value;
        // or map_time[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // Find first entry with time > timestamp
        auto it = map_time[key].upper_bound(timestamp);
        // If all times are > timestamp, return empty string
        // else return the closest previous value
        return it == map_time[key].begin() ? "" : prev(it)->second;
    }

private:
    std::unordered_map<
        std::string,
        std::map<int, std::string>
    > map_time;
};
