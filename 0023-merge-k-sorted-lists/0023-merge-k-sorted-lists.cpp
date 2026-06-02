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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* root = new ListNode(0);
        ListNode* ans = root;

        while (!pq.empty()) {
            root->next = new ListNode(pq.top());
            root = root->next;
            pq.pop();
        }

        ListNode* res = ans->next;
        delete ans;

        return res;
    }
};