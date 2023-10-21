class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0]-1;
            int v=relations[i][1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> max_time(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                max_time[i]=time[i];
            }
        }
        while(!q.empty()){
            int sz=q.front();
            q.pop();
            
            for(auto &vec: adj[sz]){
                max_time[vec]=max(max_time[vec],max_time[sz]+time[vec]);
                indegree[vec]--;
                if(indegree[vec]==0){
                    q.push(vec);
                }
            }
        }
        return *max_element(max_time.begin(),max_time.end());
    }
};