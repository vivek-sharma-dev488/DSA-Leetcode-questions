class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                st.push(2*(st.top()));
            }
            else if(operations[i]=="+"){
                int x=st.top();
                st.pop();
                int sum=x+st.top();
                st.push(x);
                st.push(sum);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int score=0;
        while(st.size()>0){
            score+=st.top();
            st.pop();
        }
        return score;
    }
};