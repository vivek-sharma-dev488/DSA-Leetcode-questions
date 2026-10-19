class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> nge(n,-1); // index
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            // pop mark push
            while(st.size() > 0 && arr[st.top()] <= arr[i]) 
                st.pop();
            if(st.size() > 0) nge[i] = st.top();
            st.push(i);
        }
        vector<int> ans(n-k+1);
        int j = 0;
        for(int i=0;i<n-k+1;i++){
            if(j < i) j = i; // example - arr = {7 1 2 3 4 5 6} k = 4
            while(nge[j] != -1 && nge[j] < i+k) 
                j = nge[j];
            ans[i] = arr[j]; // mark the max in window
        }
        return ans;
    }
};