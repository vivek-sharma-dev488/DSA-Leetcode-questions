class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int m=rowIndex+1;    //int m=rowIndex+1;
        vector<vector<int> > v;
        for(int i=0;i<m;i++){
            vector<int> a(i+1);
            v.push_back(a);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || i==j){
                    v[i][j]=1;
                }
                else{
                    v[i][j]=v[i-1][j]+v[i-1][j-1];
                }
            }
            if(i==rowIndex){
                for(int j=0;j<=i;j++){
                    return v[i];
                }
            }
        }
        return{}; //return v[rowIndex];  
    }
};