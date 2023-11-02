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
    int ans=0;
    pair<int,int> solve(TreeNode* root){     // {sum,cnt of node}
        if(!root){
            return {0,0};
        }
        auto left_subtree=solve(root->left);
        int left_sum=left_subtree.first;
        int left_Nodecnt=left_subtree.second;
        
        auto right_subtree=solve(root->right);
        int right_sum=right_subtree.first;
        int right_Nodecnt=right_subtree.second;
        
        int sum=right_sum+left_sum+root->val;
        int Nodecnt=1+right_Nodecnt+left_Nodecnt;
        
        int avg=(sum/Nodecnt);
        
        if(avg==root->val){
            ans++;
        }
        return {sum,Nodecnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};