class Solution {
public:
    void combination(vector<vector<int>>& finalans,vector<int>& candidates,vector<int> v,int target,int idx){
        if(target==0){
            finalans.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i=idx;i<candidates.size();i++){
            v.push_back(candidates[i]);
            combination(finalans,candidates,v,target-candidates[i],i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalans;
        vector<int> v;
        combination(finalans,candidates,v,target,0);
        return finalans;
    }
};