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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left_subtree=height(root->left);
        int right_subtree=height(root->right);
        int result=max(left_subtree,right_subtree)+1;
        return result;
    }
    pair<int,int> daimeterfast(TreeNode* root){  // <daimeter,height>
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left_subtree=daimeterfast(root->left);
        pair<int,int> right_subtree=daimeterfast(root->right);
        
        int op1=left_subtree.first;
        int op2=right_subtree.first;
        int op3=left_subtree.second+right_subtree.second;
        
        pair<int,int> ans;
        ans.first=max({op1,op2,op3});
        ans.second=max(left_subtree.second,right_subtree.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==NULL){
        //     return 0;
        // }
        // int op1=diameterOfBinaryTree(root->left);
        // int op2=diameterOfBinaryTree(root->right);
        // int op3=height(root->left)+height(root->right);
        // int ans=max(op1,max(op2,op3));
        // return ans;
        return daimeterfast(root).first;
    }
};