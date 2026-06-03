class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minCapital;
        priority_queue<int> maxProfit;

        for(int i=0;i<profits.size();i++){
            minCapital.push({capital[i],profits[i]});
        }

        for(int i=0;i<k;i++){
            while(!minCapital.empty() && minCapital.top().first<=w){
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            if(maxProfit.empty()) break;

            w+=maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};