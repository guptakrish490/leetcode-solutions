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
    void reorderList(ListNode* head) {

        if(!head || !head->next || !head->next->next) return;

        ListNode* slow=head;
        ListNode* fast=head;

        ListNode*k=slow;


        while(fast && fast->next){
            k=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        k->next=nullptr;


        ListNode*prev=nullptr;
        ListNode*curr=slow;

        while(curr){
            ListNode* saved=curr->next;

            curr->next=prev;

            prev=curr;
            curr=saved;

        }

        ListNode* firstHalf=head;
        ListNode* secondHalf=prev;


        while (firstHalf && secondHalf) {
            ListNode* tmp1 = firstHalf->next;
            ListNode* tmp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = tmp1;

            firstHalf = tmp1;
            secondHalf = tmp2;
        }

        if(secondHalf){
            ListNode* tail=head;
            while(tail->next) tail=tail->next;

            tail->next=secondHalf;
        }

        
    }
};