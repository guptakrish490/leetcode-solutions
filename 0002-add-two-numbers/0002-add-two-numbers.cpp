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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode*tmp1=l1;
        ListNode*tmp2=l2;

        ListNode*result=new ListNode(0);
        ListNode* ans=result;

        int carry=0;
        while(tmp1 && tmp2){
            int prevCarry=carry;
            carry=(tmp1->val+tmp2->val+prevCarry)/10;

            tmp1->val=(tmp1->val+tmp2->val+prevCarry)%10;
            result->next=tmp1;
            
            tmp1=tmp1->next;
            tmp2=tmp2->next;

            result=result->next;
        }

        while(tmp1) {
            int prevCarry=carry;
            carry=(tmp1->val+prevCarry)/10;

            tmp1->val=(prevCarry+tmp1->val)%10;
            result->next=tmp1;

            tmp1=tmp1->next;

            result=result->next;
        }

        while(tmp2){
            int prevCarry=carry;
            carry=(tmp2->val+prevCarry)/10;

            tmp2->val=(prevCarry+tmp2->val)%10;
            result->next=tmp2;

            tmp2=tmp2->next;

            result=result->next;
        }

        if(carry){
            result->next=new ListNode(carry);
        }else{
            result->next=NULL;
        }


        return ans->next;
    }
};