class Solution {
public:
    bool solve(int n,vector<vector<int>>& edges, vector<int>adj[],vector<int>& visited, int source, int destination){
        if(source==destination) return true;
        visited[source]=true;
        for(auto it: adj[source]){
            if(!visited[it]){
                if(solve(n,edges,adj,visited,it,destination)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> visited(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return solve(n,edges,adj,visited,source,destination);
    }
};