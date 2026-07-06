class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;

        q.push({beginWord,1});
        while(!q.empty()){
            string curr=q.front().first;
            int dist=q.front().second;
            q.pop();

            if(curr==endWord) return dist;

            for(int i=0;i<curr.size();i++){
                string pattern=curr;
                for(char ch='a';ch<='z';ch++){
                    pattern[i]=ch;

                    if(st.find(pattern)!=st.end()){
                        st.erase(pattern);
                        q.push({pattern,dist+1});
                    }
                }
            }
        }

        return 0;
    }
};