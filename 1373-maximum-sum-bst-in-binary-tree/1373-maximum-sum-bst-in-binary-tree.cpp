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
    class quad{
    public:
        int sum;
        int mx;
        int mn;
        bool isBST;

        quad(int sum,int mx,int mn,bool isBST){
            this->sum=sum;
            this->mx=mx;
            this->mn=mn;
            this->isBST=isBST;
        }
    };
    int maxsum;
    quad solve(TreeNode* root){
        if(root==NULL) return {0,INT_MIN,INT_MAX,true};
        quad left=solve(root->left);
        quad right=solve(root->right);
        int sum= root->val + left.sum + right.sum;
        int mx=max(root->val,max(left.mx,right.mx));
        int mn=min(root->val,min(left.mn,right.mn));
        bool isBST=(root->val > left.mx && root->val < right.mn && left.isBST && right.isBST);
        if(isBST) maxsum=max(sum,maxsum);
        return {sum,mx,mn,isBST};
    }
    int maxSumBST(TreeNode* root) {
        maxsum=0;
        solve(root);
        return maxsum;
    }
};