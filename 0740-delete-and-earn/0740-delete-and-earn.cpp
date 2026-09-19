class Solution {
public:
    int f(int idx, vector<int>& scores, vector<int>& dp) {
        if (idx <= 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int pick = scores[idx] * idx + f(idx - 2, scores, dp);
        int notPick = f(idx - 1, scores, dp);

        return dp[idx] = max(pick, notPick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int sz = *max_element(nums.begin(), nums.end());
        vector<int> scores(sz + 1);
        vector<int> dp(sz + 1, -1);

        for (int i = 0; i < nums.size(); i++) {
            scores[nums[i]]++;
        }

        return f(sz, scores, dp);
    }
};