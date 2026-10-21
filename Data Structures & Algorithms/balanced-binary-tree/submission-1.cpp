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
    bool isBalanced(TreeNode* root) {
        int16_t height_diff = 0;

        std::function<int16_t(TreeNode* node)> dfs = [&](TreeNode* node) -> int16_t {
            if (!node)
                return 0;
            if (height_diff > 1)
                return 0; // end early for this specific problem

            int16_t left_depth = dfs(node->left);
            int16_t right_depth = dfs(node->right);

            height_diff = std::max(
                static_cast<int16_t>(std::abs(left_depth - right_depth)),
                height_diff);

            return 1 + std::max(left_depth, right_depth);
        };
        dfs(root);
        return height_diff <= 1;
    }
};
