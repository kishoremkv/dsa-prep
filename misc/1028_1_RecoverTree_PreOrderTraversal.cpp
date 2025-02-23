// leetcode url - https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
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
    TreeNode* recoverFromPreorder(string traversal) {
        int ind = 0, depth = 0;
        stack<TreeNode*> nodes;
        while(ind < traversal.size())
        {
            depth = 0;
            while(ind < traversal.size() && traversal[ind] == '-')
            {
                depth++;
                ind++;
            }
            int value = 0;
            while(ind < traversal.size() && traversal[ind] !='-' )
            {
                value = value*10 + (traversal[ind]-'0');
                ind++;
            }

            TreeNode* cur_node = new TreeNode(value);
            while(nodes.size() > depth)
            {
                nodes.pop();
            }

            if(!nodes.empty())
            {
                if(nodes.top()->left != NULL)
                {
                    nodes.top()->right = cur_node;
                }
                else 
                {
                    nodes.top()->left = cur_node;
                }
            }
            nodes.push(cur_node);
        }

        while(nodes.size() > 1)
        {
            nodes.pop();
        }
        return nodes.top();
    }
};
