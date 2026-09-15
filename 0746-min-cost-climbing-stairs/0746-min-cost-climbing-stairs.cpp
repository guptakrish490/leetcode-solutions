class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> dp(sz + 1, -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= sz; i++) {
            int currCost = 0;
            if (i < sz)
                currCost = cost[i];

            dp[i] = min(dp[i - 1] + currCost, dp[i - 2] + currCost);
        }

        return dp[sz];
    }
};