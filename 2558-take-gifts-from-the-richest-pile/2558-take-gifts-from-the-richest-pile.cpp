class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        long long sum = accumulate(gifts.begin(), gifts.end(), 0LL);

        for(int i=0;i<k;i++){
            int maxi=pq.top();
            sum-=pq.top();
            pq.pop();

            maxi=(int)sqrt(maxi);
            pq.push(maxi);
            sum+=maxi;

        }

        return sum;
    }
};