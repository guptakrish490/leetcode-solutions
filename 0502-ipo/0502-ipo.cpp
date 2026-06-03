class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        struct Compare {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>pq;
        vector<pair<int,int>> temp;

        for(int i=0;i<profits.size();i++){
            pq.push({capital[i],profits[i]});
        }

        for(int i=0;i<profits.size();i++){
            if(k==0) break;

            while(!pq.empty() && pq.top().first > w){
                temp.push_back(pq.top());
                pq.pop();
            }

            if(!pq.empty()){
                w+=pq.top().second;
                k--;
                pq.pop();
            }
            else return w;

            for(pair<int,int>& num:temp) pq.push(num);
            temp.clear();
        }

        return w;
    }
};