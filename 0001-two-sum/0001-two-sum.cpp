class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;    
        }

        for(int j=0;j<nums.size();j++){
            int complement=target-nums[j];

            if(mpp[complement]!=0 && j!=mpp[complement]) return {mpp[complement],j};
        }

        return{-1,-1};
    }
};