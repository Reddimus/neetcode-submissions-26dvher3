class LRUCache {
public:
    LRUCache(int capacity)
        : capacity(capacity) {}
    
    int get(int key) {
        auto it = key_iterator.find(key);
        if (it == key_iterator.end())
            return -1;
        
        int value = it->second->second;
        // Update cache and iterator
        cache.erase(it->second);
        cache.emplace_back(key, value);
        key_iterator[key] = std::prev(cache.end());

        return value;
    }
    
    void put(int key, int value) {
        auto it = key_iterator.find(key);
        // If key has been mapped before
        if (it != key_iterator.end())  
            cache.erase(it->second);

        if (cache.size() == capacity) {
            // Delete lru to make room for mru
            key_iterator.erase(cache.front().first);
            cache.pop_front();
        }

        cache.emplace_back(key, value);
        key_iterator[key] = std::prev(cache.end());
    }
private:
    int capacity;
    std::list<std::pair<int, int>> cache;   // DoublyLinkedList[5] = {{key_1, val_1}, ..., {key_5, val_5}}
    std::unordered_map<
        int,
        std::list<std::pair<int, int>>::iterator
    > key_iterator; // key: iterator of DoublyLinkedList
};
