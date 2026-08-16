class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int boats=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(arr[i]+arr[j]==limit){
                boats++;
                i++;
                j--;
            }
            else if(arr[i]+arr[j]<limit){
                boats++;
                i++;
                j--;
            }
            else {
                boats++;
                j--;
            }
        }
        return boats;
    }
};