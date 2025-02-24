// leetcode url - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23
// Time Complexity - O(N)

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
    int preind = 0, postind = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // root left right
        // left right root
    
        // [1,2,4,5,3,6,7]
        // [4,5,2,6,7,3,1]

        // if(preind == preorder.size() || postind == postorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[preind++]);

        if(root->val != postorder[postind])
        {
            root->left = constructFromPrePost(preorder, postorder);
        }
        if(root->val != postorder[postind])
        {
            root->right = constructFromPrePost(preorder, postorder);
        }
        postind++;
        return root;
    }
};
