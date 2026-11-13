/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,vector<int>& v){
        if(root==NULL) return;
        dfs(root->left,v); 
        v.push_back(root->val);
        dfs(root->right,v); 
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        int ans;
        dfs(root,v);
        for(int i=0;i<k;i++){
            ans=v[i];
        }
        return ans;
    }
};