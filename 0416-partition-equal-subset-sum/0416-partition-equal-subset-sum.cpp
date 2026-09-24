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

        vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));

        return f(n - 1, totalSum / 2, nums, dp);
    }
};