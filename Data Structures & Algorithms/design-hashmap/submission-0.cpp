class MyHashMap {
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        hash_table[hash(key)][key] = value;        
    }
    
    int get(int key) {
        std::map<int, int>& tree = hash_table[hash(key)];
        auto it = tree.find(key);
        return it == tree.end() ? -1 : it->second;
    }
    
    void remove(int key) {
        hash_table[hash(key)].erase(key); 
    }

private:
    const std::size_t hash(std::size_t key) {
        return key % BUCKET_SIZE;
    }

    static constexpr std::size_t BUCKET_SIZE = 333334;
    std::map<int, int> hash_table[BUCKET_SIZE];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */