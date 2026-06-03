class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());

        for(int i=0;i<k;i++){
            int maxi=pq.top();
            pq.pop();

            maxi=(int)sqrt(maxi);
            pq.push(maxi);

        }

        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }

        return sum;
    }
};