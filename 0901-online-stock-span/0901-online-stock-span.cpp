    class StockSpanner {
    public:
        stack<int> st;
        vector<int> ans;
        StockSpanner() {
            
        }
        
        int next(int price) {
            int span=1;
            int curr_idx=ans.size();
            while(st.size()>0 && ans[st.top()]<=price){
                st.pop();
            }
            if(st.size()==0) span=curr_idx+1;
            else span=curr_idx-st.top();
            ans.push_back(price);
            st.push(curr_idx);
        return span;
        }
    };
