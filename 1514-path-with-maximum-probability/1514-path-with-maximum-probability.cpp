class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            double c=succProb[i];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> ans(n,INT_MIN);
        ans[start_node]=1.0;
        pq.push({1.0,start_node});
        
        while(!pq.empty()){
            pair<double,int> p=pq.top();
            pq.pop();
            double d=p.first;
            int node=p.second;
            
            for(auto &v: adj[node]){
                int adjNode=v.first;
                double dis=v.second;
                if(d*dis > ans[adjNode]){
                    ans[adjNode]=d*dis;
                    pq.push({ans[adjNode],adjNode});
                }
            }
        }
        if(ans[end_node]==INT_MIN){
            return 0.00000; 
        }else{
            return ans[end_node];
        }
        
    }
};