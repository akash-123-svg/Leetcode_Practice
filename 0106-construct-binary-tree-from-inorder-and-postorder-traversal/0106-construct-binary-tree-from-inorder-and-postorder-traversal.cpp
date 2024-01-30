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
    void createMapping(vector<int>& inorder,map<int,int>& mp){
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int &postIndex,map<int,int>&mp,int inStart,int inEnd){
        if(postIndex < 0 || inStart>inEnd) return 0;
        int element=postorder[postIndex--];
        TreeNode* root=new TreeNode(element);
        int pos=mp[element];
        root->right=solve(inorder,postorder,postIndex,mp,pos+1,inEnd);
        root->left=solve(inorder,postorder,postIndex,mp,inStart,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        map<int,int> mp;
        int postIndex=n-1;
        createMapping(inorder,mp);
        int inStart=0;
        int inEnd=n-1;
        TreeNode* ans=solve(inorder,postorder,postIndex,mp,inStart,inEnd);
        return ans;
    }
};