class Solution {
public:
    // Method 1: using dfs
    void DFS(unordered_map<int,vector<int>> &adj, int u,vector<bool>& visited){
        visited[u]=true;
        for(int &v:adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
            }
        }
    }
    
    // Method 2: using bfs
    void BFS(unordered_map<int,vector<int>> &adj, int u,vector<bool>& visited){
        queue<int> q;
        q.push(u);
        visited[u]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(int &v:adj[curr]){
                if(!visited[v]){
                    BFS(adj,v,visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                //DFS(adj,i,visited);
                BFS(adj,i,visited);
                cnt++;
            }
        }
        return cnt;
    }
};