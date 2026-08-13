class Solution {
public:
void helper(vector<int>& nums,vector <int> v, vector<vector<int>>& finalans,int idx){
    if(idx==nums.size()){
        finalans.push_back(v);
        return;
    }
    helper(nums,v,finalans,idx+1);
    v.push_back(nums[idx]);
    helper(nums,v,finalans,idx+1); 
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> v;
        vector<vector<int>> finalans;
        helper(nums,v,finalans,0);
        return finalans;
    }
};