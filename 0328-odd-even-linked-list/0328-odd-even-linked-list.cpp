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
    ListNode* oddEvenList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode* oddDummy=new ListNode(0);
        ListNode* evenDummy=new ListNode(0);

        ListNode* oddptr=oddDummy;
        ListNode* evenptr=evenDummy;

        ListNode* temp=head;

        while(temp && temp->next){
            oddptr->next=temp;
            oddptr=oddptr->next;

            evenptr->next=temp->next;
            evenptr=evenptr->next;

            temp=temp->next->next;
        }

        if(temp){
            oddptr->next=temp;
            oddptr=oddptr->next;
        }

        oddptr->next=evenDummy->next;
        evenptr->next=NULL;

        ListNode* result=oddDummy->next;

        delete oddDummy;
        delete evenDummy;

        return result;

        


    }
};