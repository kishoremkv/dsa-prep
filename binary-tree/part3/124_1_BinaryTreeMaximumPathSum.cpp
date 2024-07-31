// leetcode url - https://leetcode.com/problems/binary-tree-maximum-path-sum/
// using DFS + Kadenes algo

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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    long dfs(TreeNode* root)
    {
        if(!root) return 0;
        int l, r, cur_max = root->val;

        l = dfs(root->left);
        r = dfs(root->right);

        if(l > 0 && l >= r)
        {
            cur_max = l + root-> val;
        }
        else if(r > 0 && r >= l)
            cur_max = r + root-> val;
        
        if(l + r > 0 && l > 0 && r > 0)
        {
            cur_max = l + r + root-> val;
            res = max((int)cur_max, res);
            return max(l+root->val, r + root->val);
        }
        res = max((int)cur_max, res);
        return cur_max;
    }
};
