class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums[0] == k;

        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        
        int count = 0;

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {

            int req = prefix[i] - k;
            if (mpp[req] > 0)
                count += mpp[req];

            mpp[prefix[i]]++;
        }

        return count;
    }
};