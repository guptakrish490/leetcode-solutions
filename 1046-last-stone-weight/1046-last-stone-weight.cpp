class Solution {
public:

    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[largest] < nums[left]) {
            largest = left;
        }
        if (right < n && nums[largest] < nums[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    void buildHeap(vector<int>& nums) {
        int n = nums.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
    }

    void insert(vector<int>&nums,int val){
        nums.push_back(val);

        int n=nums.size()-1;

        while(n>0){
            int parent=(n-1)/2;
            if(nums[parent]<nums[n]){
                swap(nums[parent],nums[n]);
                n=parent;
            }
            else return;
        }
    }


    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];

        buildHeap(stones);

        while(stones.size()>1){
            int n=stones.size();

            int first=stones[0];
            swap(stones[0],stones[n-1]);
            stones.pop_back();
            heapify(stones,stones.size(),0);

            n=stones.size();

            int second=stones[0];
            swap(stones[0],stones[n-1]);
            stones.pop_back();
            heapify(stones,stones.size(),0);

            if(first!=second){
                insert(stones,abs(first-second));
            }

        }

        return stones.empty()? 0 : stones[0];


    }
};