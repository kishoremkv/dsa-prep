// leetcode url - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Time complexity - O(N)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int cur_ind = 0;
        return dfs(preorder, inorder, 0, inorder.size()-1, cur_ind);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int l, int r, int& cur_ind)
    {
        if(l > r || cur_ind == preorder.size()) return NULL;


        TreeNode* root = new TreeNode();
        root->val = preorder[cur_ind++];
        int in_ind = -1;

        for(int i=l;i<=r;i++)
        {
            if(root->val == inorder[i])
            {
                in_ind = i; break;
            }
        }
        root->left = dfs(preorder, inorder, l, in_ind-1, cur_ind);
        root->right = dfs(preorder, inorder, in_ind+1, r, cur_ind);
        return root;
    }
};
