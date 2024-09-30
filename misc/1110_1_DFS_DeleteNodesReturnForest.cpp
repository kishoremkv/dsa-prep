// leetcode url - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/


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
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        res = {};
        unordered_set<int> um;
        for(auto x: to_delete)
        {
            um.insert(x);
        }
        dfs(root, um, true);
        return res;
    }

    TreeNode* dfs(TreeNode* root, unordered_set<int>& um, bool possible_root)
    {

        if(!root) return NULL;

        if(um.find(root->val) != um.end())
        {
            
            dfs(root->left, um, true);
            dfs(root->right, um, true);

            return NULL;
        }
        else
        {
            if(possible_root)
            {
                res.push_back(root);
            }
            root->left = dfs(root->left, um, false);
            root->right = dfs(root->right, um, false);
        }
        return root;

        
    }
};
