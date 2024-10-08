// leetcodeurl - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
// TC - O(N)
// SC - O(N) Auxilary space

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return NULL;

        if(p->val == root->val) return p;
        if(q->val == root->val) return q;

        if(q->val < root->val && p->val > root->val) return root;
        else if(p->val < root->val && q->val > root->val) return root;
        else if(q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else return lowestCommonAncestor(root->right, p, q);
    }
};
