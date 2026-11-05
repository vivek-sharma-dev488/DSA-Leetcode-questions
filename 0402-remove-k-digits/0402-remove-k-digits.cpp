class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        // remove k greater integer
        for(int i=0;i<num.length();i++){
            while(st.size()>0 && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // remove integer in increasing string
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // remove leading zero from starting
        int i=0;
        while(i<ans.length() && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        // empty string return 0
        if(ans.length()==0) return "0";
        return ans;
    }
};