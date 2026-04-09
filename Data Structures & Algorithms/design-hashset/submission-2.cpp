// Keys are in the range [0, 1,000,000], so there are 1,000,001 possible keys.
// Using 142,858 buckets means each bucket can map at most 7 distinct keys.
#define SET_MEMORY_SIZE 142858

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val = INT_MIN, TreeNode* left = nullptr, TreeNode* right = nullptr)
            : val(val), left(left), right(right) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    bool contains(int val) {
        TreeNode* node = root;
        while (node) {
            if (node->val > val)
                node->left = node;
            else if (node->val < val)
                node->right = node;
            else
                return true;
        }

        return false;
    }
    
    void add(int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }

        TreeNode *prev = nullptr, *node = root;
        while (node) {
            if (node->val > val)
                node->left = node;
            else if (node->val < val)
                node->right = node;
            else // node already exists
                return; 

            prev = node;
        }
        
        if (prev->val > val)
            prev->left = new TreeNode(val);
        else
            prev->right = new TreeNode(val);
    }

    void remove(int val) {
        root = delete_node(root, val);
    }

private:
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

            // Search min node from right sub-tree
            TreeNode* temp = node->right;
            while (temp->left)
                temp = temp->left;

            node->val = temp->val;
            node->right = delete_node(node->right, temp->val);
        }
        return node;
    }

    TreeNode* root;
};

class MyHashSet {
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

private:
    int hash(int key) {
        return key % SET_MEMORY_SIZE;
    }

    BinarySearchTree hashTable[SET_MEMORY_SIZE];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */