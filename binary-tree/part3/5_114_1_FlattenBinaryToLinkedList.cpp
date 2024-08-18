// leetcode-url: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Time complexity: O(N)
// Space complexity: O(1) - Stack space 
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
        
        if(!root) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        flatten(root->right);

        if(root->left)
        {
            TreeNode* right = root;

            while(right->right) right = right->right;
            right->right = root->left;
            flatten(right->right);
            root->left = NULL; 
        }
    }
};
