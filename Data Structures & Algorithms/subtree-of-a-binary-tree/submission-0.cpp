/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::vector<TreeNode*> nodes;
        nodes.reserve(POSSIBLE_TREE_NODES);
        nodes.push_back(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.back();
            nodes.pop_back();

            if (sameTree(node, subRoot))
                return true;
            
            if (node->left)
                nodes.push_back(node->left);
            if (node->right)
                nodes.push_back(node->right);
        }
        return false;
    }
private:
    bool sameTree(TreeNode* a, TreeNode* b) {
        std::vector<std::pair<TreeNode*, TreeNode*>> nodes;
        nodes.reserve(POSSIBLE_SUBTREE_NODES);
        nodes.push_back({a, b});
        while (!nodes.empty()) {
            auto [a, b] = nodes.back();
            nodes.pop_back();

            if (!a || !b) {
                if (a != b)
                    return false;
                continue; // Skip if pair are nullptr
            }

            if (a->val != b->val)
                return false;

            nodes.push_back({a->left, b->left});
            nodes.push_back({a->right, b->right});
        }

        return true;
    }

    static constexpr std::size_t POSSIBLE_TREE_NODES = 2001;
    static constexpr std::size_t POSSIBLE_SUBTREE_NODES = 1001;
};
