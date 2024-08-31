// Conding Ninjas URL - https://www.naukri.com/code360/problems/preorder-binary-tree_5948?interviewProblemRedirection=true&search=preorder&leftPanelTabValue=PROBLEM
// Time Complexity - O(N)
// Space Complexity - O(1)

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> res;
    TreeNode<int> * cur_node = root;

    while(cur_node)
    {

        if(cur_node->left)
        {
            TreeNode<int> * inorder_pred = cur_node->left;
            while(inorder_pred->right != NULL && inorder_pred->right != cur_node)
            {
                inorder_pred = inorder_pred->right;
            }

            if (inorder_pred->right == NULL) 
            {
                // case 2
                res.push_back(cur_node->data);

                inorder_pred->right = cur_node;
                cur_node = cur_node->left;
            }
            else if(inorder_pred->right == cur_node)
            {
                // case 3
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
