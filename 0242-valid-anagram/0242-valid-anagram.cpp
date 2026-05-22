class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        if(s.size()!=t.size())return false;

        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }

        for(int j=0;j<t.size();j++){
            if(count[t[j]-'a']==0) return false;
            count[t[j]-'a']--;
        }
        return true;
    }
};