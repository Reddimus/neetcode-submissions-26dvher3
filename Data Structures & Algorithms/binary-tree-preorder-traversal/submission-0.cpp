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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> preorder;
        preorder.reserve(PREORDER_MAX);
        std::unordered_set<int> seen;
        seen.reserve(POSSIBLE_VALUES);

        std::function<void(TreeNode* node)> traverse = [&](TreeNode* node) -> void {
            if (!node)
                return;

            if (seen.find(node->val) == seen.end()) {
                preorder.push_back(node->val);
                seen.insert(node->val);
            }
            traverse(node->left);
            traverse(node->right);
        };
        traverse(root);
        return preorder;
    }
private:
    static constexpr std::uint8_t PREORDER_MAX = 101;
    static constexpr std::uint16_t POSSIBLE_VALUES = 276;
};