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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        ListNode*prev=temp;

        ListNode*before=nullptr;
        ListNode*after=nullptr;

        int cnt=0;

        while(temp!=NULL){
            prev=temp;
            temp=temp->next;
            
            ++cnt;

            if(cnt==a) before=prev;
            if(cnt==b) after=temp;
        }

        ListNode* last=list2;

        while(last->next){
            last=last->next;
        }

        before->next=list2;
        if(after) last->next=after->next;

        return list1;


    }
};