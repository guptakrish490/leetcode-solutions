class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums[0] == k;

        vector<int> prefix(nums.size());
        unordered_map<int,int>mpp;

        prefix[0] = nums[0];
        int count=0;

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for(int i=0;i<nums.size();i++){

            int req=prefix[i]-k;
            if(req==0) count++;
            if(mpp[req]>0)count+=mpp[req];

            mpp[prefix[i]]++;
        }

        return count;
    }
};