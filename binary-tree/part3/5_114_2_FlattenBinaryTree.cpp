// leetcode url - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Time Complexity - O(N)
// Space Compleity - O(1)
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
    void flatten(TreeNode* root) {
        TreeNode* inord_pred;
        while(root)
        {
            if(root->left)
            {
                inord_pred = root->left;
                while(inord_pred->right!=NULL)
                {
                    inord_pred = inord_pred->right;
                }
                inord_pred->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
        
    }
};
