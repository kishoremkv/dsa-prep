// coding ninjas URL - https://www.naukri.com/code360/problems/inorder-traversal_3839605?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
// Time Complexity - O(2N)
// Space Complexity - O(1)

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> res;
    TreeNode* cur_node = root;

    while(cur_node)
    {
        if(cur_node->left)
        {
            TreeNode* inorder_pred = cur_node->left;
            while(inorder_pred->right != NULL && inorder_pred->right != cur_node)
            {
                inorder_pred = inorder_pred->right;
            }

            if (inorder_pred->right == NULL) 
            {
                // case 2
                inorder_pred->right = cur_node;
                cur_node = cur_node->left;
            }
            else if(inorder_pred->right == cur_node)
            {
                // case 3
                res.push_back(cur_node->data);
                cur_node = cur_node->right;
                inorder_pred->right = NULL;
            }
        }
        else
        {
            //case 1
            res.push_back(cur_node->data);
            cur_node = cur_node->right;
        }
    }
    return res;

}
