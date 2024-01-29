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
    int maxDepth(TreeNode* root) {
       if(root==NULL) return 0;
       queue<TreeNode* > q;
       q.push(root);
       int maxDepth=0;
       while(!q.empty()){
           maxDepth++;
           int sz=q.size();
           while(sz--){
               TreeNode*t=q.front();
               q.pop();
               
               if(t->left!=NULL) q.push(t->left);
               if(t->right!=NULL) q.push(t->right);
           }
       }
       return maxDepth;
    }
};