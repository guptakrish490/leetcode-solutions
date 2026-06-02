class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size()==1) return arr;

        struct Compare{
            bool operator()(const pair<int,int> &a,const pair<int,int> &b){
                if(a.second==b.second) return a.first<b.first;
                return a.second<b.second;
            }
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        vector<int> ans;

        for(int num:arr) {
            pq.push({num , abs(num-x)});
            if(pq.size()>k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};