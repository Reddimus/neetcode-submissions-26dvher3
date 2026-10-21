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
        queue<TreeNode*> pq, qq;
        if (p)
            pq.push(p);
        if (q)
            qq.push(q);
        
        while (!pq.empty() && !qq.empty()) {
            const size_t level_size = pq.size();
            if (level_size != qq.size())
                return false;

            for (int i = 0; i < level_size; ++i) {
                TreeNode *p_node = pq.front(), *q_node = qq.front();
                pq.pop(), qq.pop();

                if (p_node->val != q_node->val
                    || (!p_node->left != !q_node->left)
                    || (!p_node->right != !q_node->right))
                    return false;
                
                if (p_node->left) pq.push(p_node->left);
                if (p_node->right) pq.push(p_node->right);
                if (q_node->left) qq.push(q_node->left);
                if (q_node->right) qq.push(q_node->right);
            }
        }

        return pq.empty() && qq.empty();
    }
};
