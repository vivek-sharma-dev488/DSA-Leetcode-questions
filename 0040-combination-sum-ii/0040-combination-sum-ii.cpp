class Solution {
public:
    void combination(vector<vector<int>>& finalans,vector<int>& candidates,vector<int> v,int target,int idx){
            if(target==0){
                finalans.push_back(v);
                return;
            }
            if(target<0) return;
            for(int i=idx;i<candidates.size();i++){
                if(i>idx && candidates[i] == candidates[i-1]) continue;
                // if(candidates[i] > target) break;
                v.push_back(candidates[i]);
                combination(finalans,candidates,v,target-candidates[i],i+1);
                v.pop_back();
            }
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> finalans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combination(finalans,candidates,v,target,0);
        return finalans;
    }
};

