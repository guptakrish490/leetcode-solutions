class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> dp(sz,-1);

        int first=helper(0,cost,sz, dp);
        int second=helper(1,cost,sz, dp);

        return min(first, second);
    }

    int helper(int i, vector<int>& cost, int n, vector<int>& dp) {
        if (i >= n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];

        int leftCost = cost[i] + helper(i + 1, cost, n, dp);
        int rightCost = cost[i] + helper(i + 2, cost, n, dp);

        return dp[i]=min(leftCost, rightCost);
    }
};