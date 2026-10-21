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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::vector<std::pair<TreeNode*, TreeNode*>> nodes;
        nodes.reserve(POSSIBLE_NODES);
        nodes.push_back({p, q});

        while (!nodes.empty()) {
            auto [p, q] = nodes.back();
            nodes.pop_back();

            if (!p || !q) {
                if (p != q)
                    return false;
                continue; // Skip if pair are both nullptr
            }

            if (p->val != q->val)
                return false;
            
            nodes.push_back({p->left, q->left});
            nodes.push_back({p->right, q->right});
        }
        
        return true;
    }
private:
    static constexpr std::size_t POSSIBLE_NODES = 101;
};
