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
    void Rview(TreeNode* root, int level, vector<int>&ans){
        if(!root) return;
        if(level==ans.size()) ans.push_back(root->val);
        Rview(root->right,level+1,ans);
        Rview(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        Rview(root, 0,ans);
        return ans;
    }
};