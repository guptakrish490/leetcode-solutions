/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        
        ListNode* q=node->next;
        node->val=q->val;
        node->next=node->next->next;

        delete q;
        

    }
};