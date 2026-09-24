class Solution {
public:
    bool f(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (i == 0)
            return (nums[i] == target);

        if (dp[i][target] != -1)
            return dp[i][target];

        bool notTake = f(i - 1, target, nums, dp);
        bool take = false;
        if (nums[i] <= target)
            take = f(i - 1, target - nums[i], nums, dp);

        return dp[i][target] = take | notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 == 1)
            return false;

        int target = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(totalSum / 2 + 1, false));
        for (int i = 1; i < n; i++) {
            dp[i][0] = true;
        }

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[i - 1][t];
                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1][t - nums[i]];
                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};