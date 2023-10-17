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
    pair<bool,int> isBalancedfast(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left_subtree=isBalancedfast(root->left);
        pair<bool,int> right_subtree=isBalancedfast(root->right);
        
        bool op1=left_subtree.first; // left
        bool op2=right_subtree.first; // right
        bool op3=abs((left_subtree.second)-(right_subtree.second))<=1;
        
        pair<bool,int> ans;
        ans.second=max(left_subtree.second,right_subtree.second)+1;
        
        if(op1 && op2 && op3){
            ans.first=true;
        }else{
            ans.first=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
//         if(root==NULL){
//             return true;
//         }
//         bool op1=isBalanced(root->left);
//         bool op2=isBalanced(root->right);
//         bool op3=abs(height(root->left)-height(root->right))<=1;
        
//         if(op1 && op2 && op3){
//             return true;
//         }else{
//             return false;
//         }
          return isBalancedfast(root).first;
    }
};