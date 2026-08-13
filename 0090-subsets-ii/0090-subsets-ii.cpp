class Solution {
public:
   void helper(vector<int>& nums, vector <int> v,int idx,vector<vector<int>>& finalans,bool flag){
        // int n=
        if(idx==nums.size()){
            finalans.push_back(v);
            return;
        }
        int ch=nums[idx];
        if(idx<nums.size()-1 && ch==nums[idx+1]){
            if(flag==true) helper(nums,v,idx+1,finalans,true);
            v.push_back(nums[idx]);
            helper(nums,v,idx+1,finalans,false);
        }
        else{
            if(flag==true) helper(nums,v,idx+1,finalans,true);
            v.push_back(nums[idx]);
            helper(nums,v,idx+1,finalans,true);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> v;
        vector<vector<int>> finalans;
        sort(nums.begin(),nums.end());
        helper(nums,v,0,finalans,true);
        return finalans;
    }
};