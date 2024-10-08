//leetcode url - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/1412494903/

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
        queue<Node*> q;
        if(root)
        {
            q.push(root);
        }
        while(q.size())
        {
            int size = q.size();

            while(size--)
            {
                cout<<size<<endl;
                Node* temp = q.front();
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                if(size==0)
                {
                    if(temp)
                    temp->next = NULL;
                    continue;
                }

                temp->next = q.front();

            }
        }
        return root;
    }
};
