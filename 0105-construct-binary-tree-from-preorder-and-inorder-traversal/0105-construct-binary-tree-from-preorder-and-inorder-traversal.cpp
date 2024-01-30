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
    int preIndex=0;
    int findPos(vector<int>& inorder,int element){
        int n=inorder.size();
        for(int i=0;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd){
        if(inStart>inEnd) return 0;
        int element=preorder[preIndex++];
        TreeNode*root=new TreeNode(element);
        int pos=findPos(inorder,element);
        root->left=solve(preorder,inorder,inStart,pos-1);
        root->right=solve(preorder,inorder,pos+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int inStart=0;
        int inEnd=n-1;
        TreeNode* ans=solve(preorder,inorder,inStart,inEnd);
        return ans;
    }
};