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
    void insert(TreeNode* root,int val){
        if(root==NULL) return ;
        else if(root->val<val){
            if(root->right==NULL){
                TreeNode* t=new TreeNode(val);
                root->right=t;
            }
            else  insert(root->right,val);
        }
        else{
            if(root->left==NULL){
                TreeNode* t=new TreeNode(val);
                root->left=t;
            }
            else insert(root->left,val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++){
            insert(root,pre[i]);
        }
        return root;
    }
};