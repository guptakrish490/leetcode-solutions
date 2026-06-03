class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for (int pile : piles)
            pq.push(pile);

        for (int i = 0; i < k; i++) {
            int maxi = pq.top();
            pq.pop();

            maxi = maxi - floor((double)maxi / 2);
            pq.push(maxi);
        }

        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};