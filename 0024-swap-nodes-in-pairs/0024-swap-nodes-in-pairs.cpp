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

    void swap(ListNode* a, ListNode* b){
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
    }


    ListNode* swapPairs(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode* prev=head;
        ListNode* after=prev->next;

        while(after && after->next){
            swap(prev,after);

            prev=prev->next->next;
            after=after->next->next;
        }
        
        if(after) swap(prev,after); 

        return head;
        
    }
};