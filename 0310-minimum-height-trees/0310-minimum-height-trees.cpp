class Solution {
public:
    vector<int> Toposort(int n,vector<vector<int>>&edges,vector<int>&indegree,unordered_map<int,vector<int>>&adj){
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            ans.clear();
            int sz=q.size();
            while(sz--){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            // cout<<ans;
            for(auto &v: adj[f]){
                indegree[v]--;
                if(indegree[v]==1){
                    //ans.push_back(v);
                    q.push(v);
                }
            }
          }
        }
        return ans;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       if(n==1) return {0}; 
       vector<int> indegree(n,0);
       unordered_map<int,vector<int>> adj;
       for(auto &vec: edges){
           int a=vec[0];
           int b=vec[1];
           adj[a].push_back(b);
           adj[b].push_back(a);
           indegree[a]++;
           indegree[b]++;
       }
       return Toposort(n,edges,indegree,adj);
    }
};