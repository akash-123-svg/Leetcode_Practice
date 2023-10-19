class Solution {
public:
    bool Toposort(int n,unordered_map<int,vector<int>>&adj,vector<int>&indegree){
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    cnt++;
                    q.push(v);
                }
            }
        }
        return cnt==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>>adj;
        vector<int> indegree(n,0);
        for(auto &vec: prerequisites){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        return Toposort(n,adj,indegree);
    }
};