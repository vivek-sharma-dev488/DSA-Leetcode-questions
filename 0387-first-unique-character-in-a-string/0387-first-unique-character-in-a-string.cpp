class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        int freq[26];
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            q.push(i);
        }
        while(!q.empty()){
            int idx=q.front();
            q.pop();

            if(freq[s[idx]-'a']==1) return idx;
        }
        return -1;
    }
};