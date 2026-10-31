class LRUCache {
public:
    LRUCache(int capacity)
        : capacity(capacity),
          key_iterator(POSSIBLE_KEYS, cache.end()) {}
    
    int get(int key) {
        const auto iterator = key_iterator[key];
        if (iterator == cache.end())
            return -1;

        cache.splice(
            cache.end(),    // `pos` (iterator): Move before cache.end()
            cache,          // `source_list` (list&): Move from cache
            iterator);      // `it` (iterator): The element at iterator `it`

        return iterator->second;
    }
    
    void put(int key, int value) {
        auto iterator = key_iterator[key];
        if (iterator != cache.end()) {
            // Update value and move to MRU
            iterator->second = value;
            cache.splice(cache.end(), cache, iterator);
            return;
        }

        // Evict LRU element if we are at capacity before inserting
        if (cache.size() == capacity) {
            key_iterator[cache.front().first] = cache.end();
            cache.pop_front();
        }

        // Insert new element at the back (MRU)
        cache.emplace_back(key, value);
        key_iterator[key] = std::prev(cache.end());
    }

private:
    static constexpr std::size_t POSSIBLE_KEYS = 10001;
    const std::size_t capacity;

    std::list<std::pair<int, int>> cache; // Doubly linked list of {key, value}; front = LRU, back = MRU
    std::vector<std::list<std::pair<int, int>>::iterator> key_iterator; // key -> node iterator for doubly linked list
};
