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
    void swap(ListNode* node1,ListNode* node2){
        int tmp=node1->val;
        node1->val=node2->val;
        node2->val=tmp;
    }


    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* node=head;
        ListNode*minNode=head;

        while(node){
            ListNode* j=node->next;
            minNode=node;

            while(j){
                if(j->val<minNode->val) minNode=j;
                j=j->next;
            }

            swap(minNode,node);
            node=node->next;

        }

        return head;
    }
    
};