class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        
        for(int i=0;i<n;i++){
            bool flag=true;
            while(st.size()>0 && st.top()>0 && asteroids[i]<0){
                if(st.top()<abs(asteroids[i])) st.pop();
                else if(st.top()>abs(asteroids[i])) {
                    flag=false;
                    break;
                }
                else if(st.top()==abs(asteroids[i])){
                    st.pop();
                    flag=false;
                    break;
                }
                else st.push(asteroids[i]);
            }
        if(flag==true) st.push(asteroids[i]);
        }
        vector<int> ans(st.size());
        for(int i=ans.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};