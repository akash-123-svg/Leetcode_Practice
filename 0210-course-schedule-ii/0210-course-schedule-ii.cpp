class Solution {
public:
    vector<int>Toposort(unordered_map<int,vector<int>>&adj,int n,vector<int>&indegree){
        queue<int> q;
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    ans.push_back(v);
                    cnt++;
                    q.push(v);
                }
            }
        }
        if(cnt==n){
            return ans;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>>adj;
        vector<int> indegree(n,0);
        for(auto &vec: prerequisites){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        return Toposort(adj,n,indegree);
    }
};