class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        
        int prev1=cost[1];
        int prev2=cost[0];

        int totalCost=0;

        for (int i = 2; i <= sz; i++) {
            
            int currCost = 0;
            if (i < sz)
                currCost = cost[i];

            totalCost = min(prev1 + currCost, prev2 + currCost);
            prev2=prev1;
            prev1=totalCost;
        }

        return prev1;
    }
};