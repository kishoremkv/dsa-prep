// leetcode url - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Time Complexity - O(N)
// Space Complexity - O(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // level order traversal
        
        Node* head = root; Node* temp = root;

        while(root)
        {
            temp = root;
            while(temp)
            {
                if(temp->left)
                {
                    temp->left->next = temp->right;
                    if(temp->next)
                    {
                        temp->right->next = temp->next->left;
                    }
                }
                temp = temp->next;
            }
            root = root->left;
        }
       
        return head;
    }
};
