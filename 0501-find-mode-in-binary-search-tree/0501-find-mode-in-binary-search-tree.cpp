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
    unordered_map<int,int> mp;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int> ans;
        int maxxi=INT_MIN;
        for(auto &x: mp){
            maxxi=max(maxxi,x.second);
        }
        for(auto &y: mp){
            if(y.second==maxxi){
                ans.push_back(y.first);
            }
        }
        return ans;
    }
};