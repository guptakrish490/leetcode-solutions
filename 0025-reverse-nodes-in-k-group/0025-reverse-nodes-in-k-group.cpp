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

    ListNode* reverseList(ListNode* head,int k,ListNode*&nextHead,ListNode*&currTail){
        int cnt=0;

        currTail=head;

        ListNode*prev=nullptr;
        ListNode*curr=head;
        while(cnt<k && curr){
            cnt++;
            ListNode* saved=curr->next;
            nextHead=saved;

            curr->next=prev;

            prev=curr;
            curr=saved;
        }

        return prev;
    }



    ListNode* reverseKGroup(ListNode* head, int k) {
        //edge cases
        if(k==1 || !head || !head->next) return head;

        //count length of list

        ListNode* i=head;
        int len=0;
        while(i){ len++; i=i->next;}

        //save last tail to connect
        int groups = len / k;
        if(groups==0) return head;

        ListNode* j = head;
        for (int i = 0; i < groups * k; i++) {
            j = j->next;
        }
        ListNode* lastHead = j;

        
        ListNode*nextHead=NULL;
        ListNode*currTail=NULL;
        ListNode* result=reverseList(head,k,nextHead,currTail);


        for (int g = 1; g < groups; g++) {
            ListNode* prevTail = currTail;
            ListNode* reversedHead = reverseList(nextHead, k, nextHead, currTail);
            prevTail->next = reversedHead;
        }

        currTail->next=lastHead;

        return result;

    }
};