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
         vector<int> min_months(n,0);
         queue<int> q;
         for(int i=0;i<n;i++){
             if(indegree[i]==0){
                 q.push(i);
                 min_months[i]=time[i];
             }
         }
         while(!q.empty()){
             int sz=q.front();
             q.pop();
             
             for(auto &vec: adj[sz]){
                 min_months[vec]=max(min_months[vec],min_months[sz]+time[vec]);
                 indegree[vec]--;
                 if(indegree[vec]==0){
                     q.push(vec);
                 }
             }
         }
         return *max_element(min_months.begin(),min_months.end());
    }
};