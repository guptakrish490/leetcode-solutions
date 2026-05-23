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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || !head->next) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* i=dummy;
        int cnt=0;

        ListNode* start=nullptr;
        ListNode* end=nullptr;

        ListNode*from=nullptr;
        ListNode*to=nullptr;
        ListNode*q=i;

        while(i){


            if(cnt==left) {
                from=q;
                start=i;
            }
            if(cnt==right){
                to=i->next;
                end=i;
            }
            q=i;
            i=i->next;
            cnt++;

        }

        ListNode* prev=NULL;
        ListNode* curr=start;


        while(curr && curr!=to){
            ListNode*saved=curr->next;

            curr->next=prev;

            prev=curr;
            curr=saved;
        }

        from->next=end;
        start->next=to;

        return dummy->next;

        
    }
};