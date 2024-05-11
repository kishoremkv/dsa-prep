// leetcode url - https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool hasCarry = false;
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;

        ListNode* x;
        x = traverseLL(head);
        if(hasCarry)
        {
            x = new ListNode(1, x);
        }
        return x;
    }

    ListNode* traverseLL(ListNode* root)
    {
        if(root == NULL) return NULL;
        root->next = traverseLL(root->next);
       
        if(root->val * 2 > 9) 
        {
            root->val = (root->val*2)%10;
            if(hasCarry)
            {
                root->val = root->val + 1;
            }
            hasCarry = true;
        }
        else
        {
            root->val = (root->val*2);
            if(hasCarry)
            {
                root->val = root->val + 1;
            }
            hasCarry = false;
        }
        return root;
    }
};
