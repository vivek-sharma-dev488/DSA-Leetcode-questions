class Solution {
public:
    string makeFancyString(string s) {
        string s1="";
        int count =0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i>0 && s[i]==s[i-1]){
                if(count==2) continue;
                count++;
                s1+=s[i];
            }
            else{
                count=1; 
                s1+=s[i];
            }
        }
        return s1;
    }
};