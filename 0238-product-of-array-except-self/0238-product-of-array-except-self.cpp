class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());

        prefix[0]=1; suffix[nums.size()-1]=1;

        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }

        for(int j=nums.size()-2;j>=0;j--){
            suffix[j]=suffix[j+1]*nums[j+1];
        }

        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(prefix[i]*suffix[i]);
        }

        return ans;
    }
};