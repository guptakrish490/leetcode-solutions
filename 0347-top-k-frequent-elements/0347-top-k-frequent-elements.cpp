class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        struct Compare {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        for (auto it : mpp)
            pq.push({it.first, it.second});

        vector<int> ans;
        int cnt = 0;

        while (!pq.empty() && cnt < k) {
            ans.push_back(pq.top().first);
            pq.pop();
            cnt++;
        }

        return ans;
    }
};