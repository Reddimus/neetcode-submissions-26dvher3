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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        // recrusive depth function with diameter tracking 
        std::function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node)
                return 0;
            // At each node
            int left_depth = dfs(node->left);
            int right_depth = dfs(node->right);
            // record the max diameter = left subtree + right subtree
            diameter = std::max(left_depth + right_depth, diameter);
            return 1 + std::max(left_depth, right_depth);    
        };
        dfs(root);
        return diameter;
    }
};
