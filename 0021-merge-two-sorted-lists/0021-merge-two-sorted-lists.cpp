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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode* i = list1;
        ListNode* j = list2;

        ListNode* curr = (i->val <= j->val) ? i : j;
        ListNode* head = curr;

        while (i != NULL && j != NULL) {
            if(curr==i){
                if(i->next==NULL){
                    curr->next=j;
                    return head;
                }

                i=i->next;

                if(i->val>j->val){
                    curr->next=j;
                }
            }
            

            else if(curr==j){
                if(j->next==NULL){
                    curr->next=i;
                    return head;
                }

                j=j->next;

                if(j->val>i->val){
                    curr->next=i;
                }
            }
            
            
            curr=curr->next;
        }

        
        return head;
    }
};