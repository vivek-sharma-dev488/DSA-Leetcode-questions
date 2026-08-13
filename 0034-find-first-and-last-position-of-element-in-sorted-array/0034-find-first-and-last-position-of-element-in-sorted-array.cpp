class Solution {
public:
    void firstoccurence(vector<int>& v,vector<int>& arr, int target){
        int n=arr.size();
        int lo=0;
        int hi=n-1;
        bool flag=false;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==target){
                if(mid==0||arr[mid-1]!=target){
                    flag=true;
                    v.push_back(mid);
                    break;
                }
                else hi=mid-1;
            }
            if(arr[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        if(flag==false) v.push_back(-1);
    }
    void lastoccurence(vector<int>& v,vector<int>& arr, int target){
        int n=arr.size();
        int lo=0;
        int hi=n-1;
        bool flag=false;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==target){
                if(mid==n-1||arr[mid+1]!=target){
                    flag=true;
                    v.push_back(mid);
                    break;
                }
                else lo=mid+1;
            }
            else if(arr[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        if(flag==false) v.push_back(-1);
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> v;
        firstoccurence(v,arr,target);
        lastoccurence(v,arr,target);
        return v;
    }
};