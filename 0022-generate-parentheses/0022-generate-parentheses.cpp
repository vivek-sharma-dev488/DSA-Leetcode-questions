class Solution {
public:
    void generate(vector<string>& finalans,string s,int open,int close,int n){
        if(close==n){
            finalans.push_back(s);
            return;
        }
        if(open<n) generate(finalans,s+'(',open+1,close,n);
        if(open>close) generate(finalans,s+')',open,close+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> finalans;
        generate(finalans,"",0,0,n);
        return finalans;
    }
};