class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>adj;
        vector<int> indegree(n,0);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> Max_time(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                Max_time[i]=time[i];
            }
        }
        while(!q.empty()){
            int sz=q.front();
            q.pop();
            
            for(auto &v:adj[sz]){
                Max_time[v]=max(Max_time[v],Max_time[sz]+time[v]);
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return *max_element(Max_time.begin(),Max_time.end());
    }
};