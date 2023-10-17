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
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool op1=isBalanced(root->left);
        bool op2=isBalanced(root->right);
        bool op3=abs(height(root->left)-height(root->right))<=1;
        
        if(op1 && op2 && op3){
            return true;
        }else{
            return false;
        }
    }
};