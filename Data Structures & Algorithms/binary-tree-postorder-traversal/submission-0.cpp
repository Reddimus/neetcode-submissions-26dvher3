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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> postorder;
        postorder.reserve(101);

        std::function<void(TreeNode*)> traverse = [&](TreeNode* node) -> void {
            if (!node) return;

            traverse(node->left);
            traverse(node->right);
            postorder.push_back(node->val);
        };
        traverse(root);
        return postorder;
    }
};