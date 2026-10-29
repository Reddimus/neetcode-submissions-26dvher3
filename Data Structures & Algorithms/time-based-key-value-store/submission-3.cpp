class TimeMap {
public:
    TimeMap() {
    }
    
    void set(const string key, const string value, const int timestamp) {
        map_time[key][value][timestamp] = true; 
    }
    
    string get(string key, int timestamp) {
        if (map_time.find(key) == map_time.end() ||
        map_time[key].empty())
            return "";

        for (int time = timestamp; time >= 0; --time)  
            for (const auto& [value, timeline] : map_time[key])  
                if (timeline[time]) // if map_time[key][value][timestamp]
                    return value;
        return "";
    }

private:
    static constexpr std::size_t TIMELINE_SIZE = 10000001;
    std::unordered_map<
        std::string,
        std::unordered_map<std::string, std::bitset<TIMELINE_SIZE>>
    > map_time;
};
