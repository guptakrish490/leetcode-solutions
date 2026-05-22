class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        if(n==1) return 1;

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[position[i]]=speed[i];


        sort(position.begin(),position.end());

        vector<double> time(n);

        for(int i=0;i<n;i++){
            time[i] = (double)(target-position[i]) / (double)mpp[position[i]];
        }




        double curr=time[n-1];
        int cnt=1;

        for(int i=n-2;i>=0;i--){
            if(time[i]>curr) {
                cnt++;
                curr=time[i];
            }
        }

        return cnt;


    }
};