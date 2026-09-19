#pragma GCC optimize("Ofast")

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int sz = *max_element(nums.begin(), nums.end());
        vector<int> scores(sz + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            scores[nums[i]]++;
        }

        int prev2 = 0;
        int prev = scores[1];

        for (int i = 2; i <= sz; i++) {
            int curr = max(scores[i] * i + prev2, prev);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};