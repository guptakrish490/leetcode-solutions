class Solution {
public:
    double distance(int x, int y) {
        if (x == 0)
            return abs(y);
        if (y == 0)
            return abs(x);

        return sqrt((pow(x, 2)) + (pow(y, 2)));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct Compare {
            bool operator()(const pair<vector<int>, double>& a,
                            const pair<vector<int>, double>& b) {
                return a.second > b.second;
            }
        };

            priority_queue < pair<vector<int>, double> , vector<pair<vector<int>, double>>, Compare> pq;


            for(vector<int> point:points){
                pq.push({point,distance(point[0],point[1])});
            }

            vector<vector<int>>ans;
            for(int i=0;i<k;i++){
                ans.push_back(pq.top().first);
                pq.pop();
            }

            return ans;
    }
};