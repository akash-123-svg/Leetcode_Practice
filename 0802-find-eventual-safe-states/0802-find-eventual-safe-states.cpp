class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNode;
        int n=graph.size();
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto &vec: graph[i]){
                adj[vec].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int sz=q.front();
            q.pop();
            safeNode.push_back(sz);
            
            for(auto &vec: adj[sz]){
                indegree[vec]--;
                if(indegree[vec]==0){
                    q.push(vec);
                }
            }
        }
        sort(safeNode.begin(),safeNode.end());
        return safeNode;
    }
};