class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec: times){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(n+1,INT_MAX);
        ans[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &vec: adj[node]){
                int adjNode=vec.first;
                int dis=vec.second;
                
                if(d+dis < ans[adjNode]){
                    ans[adjNode]=d+dis;
                    pq.push({d+dis,adjNode});
                }
            }
        }
        int res=INT_MIN;
        for(int i=1;i<=n;i++){
            res=max(res,ans[i]);
        }
        if(res==INT_MAX){
            return -1;
        }else{
            return res;
        }
    }
};