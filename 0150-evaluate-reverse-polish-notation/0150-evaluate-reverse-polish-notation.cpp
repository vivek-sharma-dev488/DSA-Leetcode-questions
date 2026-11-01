class Solution {
public:
    int operation(int a,int b, string str){
            if(str=="+") return a+b;
            else if(str=="-") return a-b;
            else if(str=="*") return a*b;
            else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int b=st.top();
                st.pop();

                int a=st.top();
                st.pop();
                st.push(operation(a,b,tokens[i]));
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};