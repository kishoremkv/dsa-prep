// leetcode url - https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string left, right; 
        dfs(root, startValue, left);
        dfs(root, destValue, right);
        // cout<<left<<endl;
        // cout<<right<<endl;
        int i = 0;
        for( i=0;i<min(left.size(), right.size()); i++)
        {
            if(left[i] != right[i]) break;
        }

        string res = "";

        for(int j=0;j<(left.size() - i);j++)
        {
            res.push_back('U');
        }

        res = res + right.substr(i, right.size() - i);

        return res;
    }

    string dfs(TreeNode* root, int val, string &str)
    {

        if(root->val == val)
        {
            cout<<str<<endl;
            return str;
        }
        string res = "";
        if(root->left)
        {
            str.push_back('L');
            res = dfs(root->left, val, str);
            if(res != "") return res;
            str.pop_back();

        }
        if(root->right)
        {
            str.push_back('R');

            res = dfs(root->right, val, str);
            if(res != "") return res;
            str.pop_back();

        }
        return res;
    }

};
