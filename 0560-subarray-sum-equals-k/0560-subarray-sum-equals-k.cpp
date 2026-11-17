class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums[0] == k;

        unordered_map<int, int> mpp;
        int prefix=0;
        mpp[0] = 1;

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            int req = prefix - k;
            if (mpp[req] > 0)
                count += mpp[req];

            mpp[prefix]++;
        }

        return count;
    }
};