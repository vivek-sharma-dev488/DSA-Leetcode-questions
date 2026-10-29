class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>  q;
        int n=deck.size();
        vector<int> arr(n);
        int idx=0;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        while(q.size()>0){
            arr[idx++]=q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        sort(deck.begin(),deck.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[arr[i]]=deck[i];
        }
        return ans;
    }
};