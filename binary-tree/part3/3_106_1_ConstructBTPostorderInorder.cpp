//leetcode-url - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/1352184248/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = postorder.size() - 1;
        return dfs(inorder, postorder, 0, (int)postorder.size()-1, ind);
    }

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int l, int r, int& ind)
    {
        if(l > r || ind == -1)
        {
            return NULL;
        }
        int cur_ind;
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i] == postorder[ind])
            {
                cur_ind = i;
                break;
            }
        }
        TreeNode* root = new TreeNode();
        root->val = postorder[ind--];
        root->right = dfs(inorder, postorder, cur_ind+1, r, ind);
        root->left = dfs(inorder, postorder, l, cur_ind-1, ind);
        
        return root;

    }
};
