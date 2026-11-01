class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<bool> v(s.size(),true);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()==true){
                    v[i]=false;
                }
                else st.pop();
            }
        }
        while(!st.empty()){
            v[st.top()]=false;
            st.pop();
        }
        string ans="";
        for(int i=0;i<v.size();i++){
            if(v[i]==true){
                ans+=s[i];
            }
        }
        return ans;
    }
};