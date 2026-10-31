class LRUCache {
public:
    LRUCache(int capacity)
        : capacity(capacity),
          key_iterator(POSSIBLE_KEYS, cache.end()) {}
    
    int get(int key) {
        auto iterator = key_iterator[key];
        if (iterator == cache.end())
            return -1;
        
        const int value = iterator->second;

        // Move found node to Most Recently Used position (MRU)
        cache.erase(iterator);
        cache.emplace_back(key, value);
        key_iterator[key] = std::prev(cache.end()); 

        return value;
    }
    
    void put(int key, int value) {
        if (key_iterator[key] != cache.end())
            cache.erase(key_iterator[key]);

        cache.emplace_back(key, value);
        key_iterator[key] = std::prev(cache.end()); 

        // Evict LRU element if capacity is exceeded
        if (cache.size() > capacity) {
            key_iterator[cache.front().first] = cache.end();
            cache.pop_front();
        }
    }

private:
    static constexpr std::size_t POSSIBLE_KEYS = 10001;
    const std::size_t capacity;

    std::list<std::pair<int, int>> cache; // Doubly linked list of {key, value}; front = LRU, back = MRU
    std::vector<std::list<std::pair<int, int>>::iterator> key_iterator; // key -> node iterator for doubly linked list
};
