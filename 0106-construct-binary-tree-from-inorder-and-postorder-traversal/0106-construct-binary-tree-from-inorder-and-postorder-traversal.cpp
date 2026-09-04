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
    TreeNode* build(vector<int>& in, int inlo,int inhi, vector<int>& post, int ptlo, int pthi){
        if(inlo>inhi) return NULL;
        TreeNode* root=new TreeNode(post[pthi]);
        if(inlo==inhi) return root;
        int i=inlo;
        while(i<inhi){
            if(in[i]==post[pthi]) break;
            i++;
        }
        int leftCount=i-inlo;
        int rightCount=inhi-i;
        root->left=build(in,inlo,i-1,post,ptlo,ptlo+leftCount-1);
        root->right=build(in,i+1,inhi,post,ptlo+leftCount,pthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        return build(in,0,n-1,post,0,n-1);
    }
};