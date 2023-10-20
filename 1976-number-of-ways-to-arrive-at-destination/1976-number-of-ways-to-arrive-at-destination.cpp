class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
       unordered_map<ll,vector<pair<ll,ll>>> adj;
       for(auto &vec: roads){
           int u=vec[0];
           int v=vec[1];
           int t=vec[2];
           adj[u].push_back({v,t});
           adj[v].push_back({u,t});
       }
       priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
       vector<ll> ans(n,LONG_MAX);
       vector<ll> dp(n,0);
       ans[0]=0;
       dp[0]=1;
       pq.push({0,0});
       while(!pq.empty()){
           ll d=pq.top().first;
           ll node=pq.top().second;
           pq.pop();
           
           for(auto vec: adj[node]){
               ll adjNode=vec.first;
               ll wt=vec.second;
               
               if(d+wt < ans[adjNode]){
                   ans[adjNode]=d+wt;
                   pq.push({d+wt,adjNode});
                   dp[adjNode]=dp[node];
               }
               else if(d+wt == ans[adjNode]){
                   dp[adjNode]=(dp[adjNode]+dp[node])%MOD;
               }
           }
       }
       return dp[n-1];
    }
};