class Solution {
public:
    void heapify(vector<int>& nums,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && nums[largest]<nums[left]){
            largest=left;
        }
        if(right<n && nums[largest]<nums[right]){
            largest=right;
        }

        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,n,largest);
        }

    }


    void buildHeap(vector<int>& nums){
        int n=nums.size();

        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {

        if(nums.size()==1) return nums[0];
        
        buildHeap(nums);

        int n=nums.size();
        int ans;

        for(int i=k;i>0;i--){
            ans=nums[0];
            swap(nums[0],nums[--n]);
            heapify(nums,n,0);
        }

        return ans;
    }
};