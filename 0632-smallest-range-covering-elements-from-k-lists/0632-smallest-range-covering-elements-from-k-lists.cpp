class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        struct Node {
            int val;
            int listIdx;
            int elemIdx;
        };

        struct Compare {
            bool operator()(const Node& a, const Node& b) {
                return a.val > b.val;
            }
        };

        priority_queue<Node, vector<Node>, Compare> pq;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        int st = 0, end = INT_MAX;

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();

            int mini = cur.val;

            if (maxi - mini < end - st) {
                st = mini;
                end = maxi;
            }

            if (cur.elemIdx + 1 < nums[cur.listIdx].size()) {
                int nextVal = nums[cur.listIdx][cur.elemIdx + 1];
                pq.push({nextVal, cur.listIdx, cur.elemIdx + 1});
                maxi = max(maxi, nextVal);
            } else
                break;
        }

        return {st, end};
    }
};