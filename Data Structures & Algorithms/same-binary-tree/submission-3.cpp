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
        if (!p || !q) return p == q;
        
        queue<TreeNode*> pq, qq;
        pq.push(p), qq.push(q);
        
        while (!pq.empty() && !qq.empty()) {
            TreeNode *p_node = pq.front(), *q_node = qq.front();
            pq.pop(), qq.pop();

            if (p_node->val != q_node->val
                || ((p_node->left == nullptr) != (q_node->left == nullptr))
                || ((p_node->right == nullptr) != (q_node->right == nullptr)))
                return false;
            
            if (p_node->left) pq.push(p_node->left);
            if (p_node->right) pq.push(p_node->right);
            if (q_node->left) qq.push(q_node->left);
            if (q_node->right) qq.push(q_node->right);
        }

        return pq.empty() && qq.empty();
    }
};
