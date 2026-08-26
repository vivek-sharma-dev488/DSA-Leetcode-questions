class Solution {
public:
    int compress(vector<char>& s) {
        int n=s.size();
        string ans;
        int i=0,j=0;
        while(j<n){
            if(s[i]==s[j]) j++;
            else{
                int len=j-i;
                ans.push_back(s[i]);
                if(len!=1) ans+=to_string(len);
                i=j;
            }
        }
        int len=j-i;
        ans.push_back(s[i]);
        if(len!=1) ans+=to_string(len);
        i=j;

        vector<char> v;
        for(int i=0;i<ans.length();i++){
            v.push_back(ans[i]);
        }
        s=v;
        return s.size();
    }
};