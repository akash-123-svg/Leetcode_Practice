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
    vector<int> largestValues(TreeNode* root) {
       vector<int> ans;
       queue<TreeNode*> q;
       q.push(root);
       if(!root) return ans;
       while(!q.empty()){
           int sz=q.size();
           int maxx=INT_MIN;
           for(int i=0;i<sz;i++){
               TreeNode*t=q.front();
               q.pop();
               if(t->left !=NULL){
                   q.push(t->left);
               }
               if(t->right!=NULL){
                   q.push(t->right);
               }
               maxx=max(maxx,t->val);
           }
           ans.push_back(maxx);
       }
       return ans;
    }
};