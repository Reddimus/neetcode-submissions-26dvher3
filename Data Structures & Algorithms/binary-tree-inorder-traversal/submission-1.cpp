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
        std::vector<int> inorder_list;
        std::function<void(TreeNode* node)> inorder = [&](TreeNode* node) -> void {
            if (!node) return;
            
            inorder(node->left);
            inorder_list.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        return inorder_list;
    }
};