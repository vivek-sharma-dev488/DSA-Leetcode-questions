class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans1(n,-1);
        vector<int> ans2(n,n);
        int max=0;
        // PREVIOUS SMALLER
        for(int i=0;i<n;i++){
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()!=0) ans1[i]=st.top();
            st.push(i);
        }
        // NEXT SMALLER
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()!=0) ans2[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int width=ans2[i]-ans1[i]-1;
            int height=arr[i];
            int area=width*height;
            if(area>max) max=area;
        }
        return max;
    }
};