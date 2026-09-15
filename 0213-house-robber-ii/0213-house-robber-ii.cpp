class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        int case1 = robLinear(vector<int>(nums.begin(), nums.end() - 1));
        int case2 = robLinear(vector<int>(nums.begin() + 1, nums.end()));

        return max(case1, case2);
    }

    int robLinear(vector<int> nums) {
        int prev1 = 0, prev2 = 0;

        for (int num : nums) {
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};