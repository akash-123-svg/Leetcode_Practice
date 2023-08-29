class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node){
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> res(n,INT_MIN);
        res[start_node]=1.0;
        pq.push({1.0,start_node});
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double dis=it.first;
            int node=it.second;
            for(auto &vec: adj[node]){
               int adjNode=vec.first;
               double edgeWeight=vec.second;
               if(edgeWeight*dis > res[adjNode]){
                   res[adjNode]=edgeWeight*dis;
                   pq.push({res[adjNode],adjNode});
               }
            }
        }
        if(res[end_node]==INT_MIN){
            return 0.00000;
        }else{
            return res[end_node];
        }
    }
};