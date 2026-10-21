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
    // T: O(n)
    // M: O(h) = O(log(n)) on a balanced tree = O(n) on a degenerate tree
    // Where n is the number of nodes and h is the height of the tree
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        // recrusive depth function with height subtree difference
        std::function<int16_t(TreeNode* node)> dfs = [&](TreeNode* node) -> int16_t {
            if (!node || !balanced)
                return 0;
            // At each node
            int16_t left_depth = dfs(node->left);
            int16_t right_depth = dfs(node->right);
            // record if balanced based on the height subtree difference
            balanced &= static_cast<int16_t>(std::abs(left_depth - right_depth)) <= 1;

            return 1 + std::max(left_depth, right_depth);
        };
        dfs(root);
        return balanced;
    }
};
