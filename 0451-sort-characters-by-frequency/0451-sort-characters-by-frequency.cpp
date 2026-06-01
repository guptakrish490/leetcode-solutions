class Solution {
public:
    string frequencySort(string s) {
        struct Compare {
            bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
                return a.second < b.second;
            }
        };

        priority_queue< pair<char,int>, vector<pair<char,int>>, Compare> pq;
        unordered_map<char,int>mpp;

        for(char c:s) mpp[c]++;

        for(auto it:mpp) pq.push({it.first,it.second});

        string res;
        while(!pq.empty()){
            int k=pq.top().second;

            for(int i=0;i<k;i++){
                res.push_back(pq.top().first);
            }
            
            pq.pop();
        }

        return res;
    }
};