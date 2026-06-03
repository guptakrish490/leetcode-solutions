class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long maxScore=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;

        struct Compare{
            bool operator()(const pair<int,int>& a,const pair<int,int>& b){
                return a.second>b.second;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>temp;
        
        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i],nums2[i]});
        }
        
        long long mini=INT_MAX; long long sum=0;

        for(int i=0;i<k;i++){
            temp.push(pq.top());

            sum+=pq.top().first;
            mini=temp.top().second;

            pq.pop();
        }
        maxScore=max(maxScore,sum*mini);
        

        while(!pq.empty()){

            sum-=temp.top().first;
            temp.pop();

            int curr=pq.top().first;
            temp.push(pq.top());
            pq.pop();

            mini=temp.top().second;
            sum+=curr;

            maxScore=max(maxScore,sum*mini);
            
        }

        return maxScore;

    }
};