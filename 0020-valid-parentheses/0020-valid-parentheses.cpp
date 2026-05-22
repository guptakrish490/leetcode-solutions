class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char,char>mpp;
        
        mpp[']']='[';  mpp[')']='(';  mpp['}']='{';

        for(char c:s){

            if(c=='(' || c=='[' || c=='{') st.push(c);
            else{
                if(st.empty()) return false;

                if(st.top()==mpp[c]) st.pop();
                else return false;
            }

        }
        return st.empty();
    }
};