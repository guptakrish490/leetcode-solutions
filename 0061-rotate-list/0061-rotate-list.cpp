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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next) return head;

        ListNode* slow=head;
        ListNode*prevSlow=nullptr;

        ListNode*fast=head;
        ListNode*prevFast=nullptr;

        int len=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }

        k=k%len;
        if(k==0) return head;
        
        int cnt=1;

        while(fast){
            if(cnt>k){
                prevSlow=slow;
                slow=slow->next;
            }

            prevFast=fast;
            fast=fast->next;
            cnt++;
        }

        prevFast->next=head;
        prevSlow->next=NULL;

        return slow;
    }
};