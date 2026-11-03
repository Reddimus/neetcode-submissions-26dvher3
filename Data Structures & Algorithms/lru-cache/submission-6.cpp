struct DoublyNode {
    int key, val;
    DoublyNode *prev, *next;
    DoublyNode(int key = INT_MIN, int val = INT_MIN, DoublyNode* prev = nullptr, DoublyNode* next = nullptr) :
        key(key), val(val), prev(prev), next(next) {} 
};

class LRUCache{
public:
    LRUCache(int capacity)
        : size(0), 
          capacity(capacity),
          key_node(POSSIBLE_KEYS, nullptr) {
        lru_dummy = new DoublyNode();
        mru_dummy = new DoublyNode();
        lru_dummy->next = mru_dummy;
        mru_dummy->prev = lru_dummy;
    }
    
    int get(int key) {
        DoublyNode* node = key_node[key];
        if (!node)  
            return -1;
        
        const int value = node->val;
        // Update cache
        delete_node(node);
        DoublyNode* mru = new DoublyNode(key, value);
        insert_node(mru);
        // Update look up key for node pointer
        key_node[key] = mru;
        return value;
    }
    
    void put(int key, int value) {
        DoublyNode* node = key_node[key];
        if (node) { // if previously mapped
            delete_node(node);
        } else if (size == capacity) {
            key_node[lru_dummy->next->key] = nullptr;
            delete_node(lru_dummy->next);
        }

        DoublyNode* mru = new DoublyNode(key, value);
        insert_node(mru);
        key_node[key] = mru;
    }
private:
    void delete_node(DoublyNode* node) {
        DoublyNode *prev_neighbor = node->prev, *next_neighbor = node->next;
        prev_neighbor->next = next_neighbor, next_neighbor->prev = prev_neighbor;
        delete node;
        --size;
    }

    void insert_node(DoublyNode* node) {
        DoublyNode* prev_neighbor = mru_dummy->prev;
        prev_neighbor->next = node, mru_dummy->prev = node;
        node->prev = prev_neighbor, node->next = mru_dummy;
        ++size;
    }

    static constexpr std::size_t POSSIBLE_KEYS = 10001;

    int size, capacity;
    DoublyNode *lru_dummy, *mru_dummy;  // Doubly linked list cache
    std::vector<DoublyNode*> key_node;
};
