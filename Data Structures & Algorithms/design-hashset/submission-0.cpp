// Keys are in the range [0, 1,000,000], so there are 1,000,001 possible keys.
// Using 333,334 buckets means each bucket can map at most 3 distinct keys.
#define SET_MEMORY_SIZE 333334

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int value = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(value), left(left), right(right) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    bool search_node(TreeNode* node, int val) {
        if (!node)
            return false;

        if (val < node->val)
            return search_node(node->left, val);
        else if (val > node->val)
            return search_node(node->right, val);
        return true;
    }

    TreeNode* insert_node(TreeNode* node, int& val) {
        if (!node)
            return new TreeNode(val);
        
        if (val < node->val)
            node->left = insert_node(node->left, val);
        else if (val > node->val)
            node->right = insert_node(node->right, val);
        return node;
    }

    TreeNode* search_min_node(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    TreeNode* delete_node(TreeNode* node, int& val) {
        if (!node)
            return nullptr;

        if (val < node->val) {
            node->left = delete_node(node->left, val);
        } else if (val > node->val) {
            node->right = delete_node(node->right, val);
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

            TreeNode* temp = search_min_node(node->right);
            node->val = temp->val;
            node->right = delete_node(node->right, temp->val);
        }
        return node;
    }
public:
    BinarySearchTree() : root(nullptr) {}

    bool contains(int val) {
        return search_node(root, val);
    }
    
    void add(int val) {
        root = insert_node(root, val);
    }

    void remove(int val) {
        root = delete_node(root, val);
    }
};

class MyHashSet {
private:
    BinarySearchTree hashTable[SET_MEMORY_SIZE];

    int hash(int key) {
        return key % SET_MEMORY_SIZE;
    }
public:
    MyHashSet() {}
    
    void add(int key) {
        hashTable[hash(key)].add(key);
    }
    
    void remove(int key) {
        hashTable[hash(key)].remove(key);
    }
    
    bool contains(int key) {
        return hashTable[hash(key)].contains(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */