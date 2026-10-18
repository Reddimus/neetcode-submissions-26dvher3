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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        std::vector<int> left_tree = inorderTraversal(root->left);

        left_tree.push_back(root->val);

        std::vector<int> right_tree = inorderTraversal(root->right);
        left_tree.insert(left_tree.end(), right_tree.begin(), right_tree.end());

        return left_tree;
    }
};