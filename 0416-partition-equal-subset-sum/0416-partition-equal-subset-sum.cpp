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

        vector<bool> prev(target + 1, false);
        for (int i = 1; i < n; i++) {
            prev[0] = true;
        }

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true;
            for (int t = 1; t <= target; t++) {
                bool notTake = prev[t];
                bool take = false;
                if (nums[i] <= t)
                    take = prev[t - nums[i]];
                curr[t] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};