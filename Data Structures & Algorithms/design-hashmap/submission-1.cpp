struct TreeNode {
    int key, value;
    TreeNode *left, *right;
    TreeNode(int key = INT_MIN, int value = INT_MIN, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : key(key), value(value), left(left), right(right) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}
 
    void put(int key, int value) {
        if (!root) {
            root = new TreeNode(key, value);
            return;
        }

        TreeNode *parent = nullptr, *node = root;
        while (node) {
            if (key < node->key) {
                node->left = node;
            } else if (key > node->key) {
                node->right = node;
            } else {
                node->value = value;
                return;
            }

            parent = node;
        }

        if (key < parent->key)
            parent->left = new TreeNode(key, value);
        else
            parent->right = new TreeNode(key, value);
    }

    int get(int key) {
        TreeNode* node = root;
        while (node) {
            if (key < node->key)
                node = node->left;
            else if (key > node->key)
                node = node->right;
            else
                return node->value;
        }
        return -1;  // not found
    }

    void remove(int key) {
        root = remove_node(root, key);
    }

private:
    TreeNode* remove_node(TreeNode* node, int key) {
        if (!node)
            return nullptr;

        if (key < node->key) {
            node->left = remove_node(node->left, key);
        } else if (key > node->key) {
            node->right = remove_node(node->right, key);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Search replaceable min node of right sub-tree 
            TreeNode* temp = node->right;
            while (temp->left)
                temp = temp->left;
            // "Swap" node and delete target leaf node
            node->key = temp->key;
            node->value = temp->value;
            node->right = remove_node(node->right, temp->key);
        }
        return node;
    }

    TreeNode* root;
};

class MyHashMap {
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        hash_table[hash(key)].put(key, value);
    }
    
    int get(int key) {
        return hash_table[hash(key)].get(key);
    }
    
    void remove(int key) {
        hash_table[hash(key)].remove(key);
    }

private:
    const std::size_t hash(std::size_t key) {
        return key % BUCKET_SIZE;
    }

    static constexpr std::size_t BUCKET_SIZE = 333334;
    BinarySearchTree hash_table[BUCKET_SIZE];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */