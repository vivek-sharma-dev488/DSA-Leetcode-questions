class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> v;
        int n=arr.size();
         int i=0;
         int j=n-1;
         while(i<j){
            if(arr[i]+arr[j]==target){
                v.push_back(i+1);
                v.push_back(j+1);
                break;
            }
            else if(arr[i]+arr[j]<target){
                i++;
            }
            else j--;
         }
         return v;
    }
};