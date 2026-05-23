/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return nullptr;

        unordered_map<Node*,int> idx1;
        unordered_map<Node*,int> randomIdx;
        unordered_map<int,Node*> idx2;

        //to store index of each node
        Node*tmp=head;
        int cnt=0;
        while(tmp){
            idx1[tmp]=cnt++;
            tmp=tmp->next;
        }

        //to store index of node->random for each node
        tmp=head;
        while(tmp){
            if(tmp->random) randomIdx[tmp]=idx1[tmp->random];
            else randomIdx[tmp]=-1;

            tmp=tmp->next;
        }

        //building node with next pointers only and indexing
        Node*result=new Node(head->val);
        Node* curr=result;

        int i=0;
        idx2[i++]=curr;

        tmp=head;
        while(tmp){
            tmp=tmp->next;

            if(tmp){
                curr->next=new Node(tmp->val);
                curr=curr->next;
                idx2[i++]=curr;
            }
        }

        tmp=head;
        curr=result;

        while(curr && tmp){
            if(randomIdx[tmp]==-1) curr->random=nullptr;
            else{
                int idx=randomIdx[tmp];
                curr->random=idx2[idx];
            }

            curr=curr->next;
            tmp=tmp->next;
        }

        return result;

        


    }
};