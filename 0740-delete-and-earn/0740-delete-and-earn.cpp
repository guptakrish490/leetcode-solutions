class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int sz = *max_element(nums.begin(), nums.end());
        vector<int> scores(sz + 1, 0);
        vector<int> dp(sz + 1, -1);

        for (int i = 0; i < nums.size(); i++) {
            scores[nums[i]]++;
        }

        dp[0] = 0;
        dp[1] = scores[1];

        for (int i = 2; i <= sz; i++) {
            dp[i] = max(scores[i] * i + dp[i - 2], dp[i - 1]);
        }

        return dp[sz];
    }
};