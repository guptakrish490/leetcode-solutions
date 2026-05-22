class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0, end=height.size()-1;

        int maxi=0;
        while(st<end){
            int area=min(height[st],height[end])*(end-st);
            maxi=max(area,maxi);

            if(height[st]>=height[end]) end--;
            else st++;
        }
        return maxi;
    }
};