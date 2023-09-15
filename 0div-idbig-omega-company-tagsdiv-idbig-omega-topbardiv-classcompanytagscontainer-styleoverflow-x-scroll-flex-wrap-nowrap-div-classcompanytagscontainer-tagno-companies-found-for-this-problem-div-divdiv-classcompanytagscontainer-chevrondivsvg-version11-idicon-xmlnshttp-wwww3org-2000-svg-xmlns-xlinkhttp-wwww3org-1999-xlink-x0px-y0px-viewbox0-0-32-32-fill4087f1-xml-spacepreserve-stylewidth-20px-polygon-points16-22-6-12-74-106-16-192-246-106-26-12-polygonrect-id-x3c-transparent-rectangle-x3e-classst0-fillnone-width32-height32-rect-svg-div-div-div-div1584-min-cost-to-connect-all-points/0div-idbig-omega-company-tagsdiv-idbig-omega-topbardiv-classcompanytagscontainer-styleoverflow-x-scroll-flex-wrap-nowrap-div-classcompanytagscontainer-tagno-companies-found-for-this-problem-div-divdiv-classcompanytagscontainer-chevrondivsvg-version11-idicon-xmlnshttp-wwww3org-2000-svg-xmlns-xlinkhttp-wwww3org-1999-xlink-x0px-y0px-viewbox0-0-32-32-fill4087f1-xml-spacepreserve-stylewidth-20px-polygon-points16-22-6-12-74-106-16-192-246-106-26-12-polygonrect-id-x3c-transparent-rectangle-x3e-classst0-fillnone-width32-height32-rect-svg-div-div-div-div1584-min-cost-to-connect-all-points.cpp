class Solution {
public:
    void makeset(vector<int>& parent,vector<int>& rank,int n){
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=0;
            }
    }
    int findParent(vector<int>& parent,int node){
          if(parent[node]==node){
              return node;
          }
          return parent[node]=findParent(parent,parent[node]);
    }
    void Unionset(int u,int v,vector<int>& parent,vector<int>& rank){
           u=findParent(parent,u);
           v=findParent(parent,v);
           if(rank[u]>rank[v]){
               parent[v]=u;
           }
           else if(rank[u]<rank[v]){
               parent[u]=v;
           }
           else{
                parent[u]=v;
                rank[v]++;
           }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
      int n=points.size();
      vector<int> parent(n);
      vector<int> rank(n);
      makeset(parent,rank,n);
      vector<pair<int,pair<int,int>>>adj;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
              adj.push_back({dist,{i,j}});
          }
      }
      sort(begin(adj),end(adj));
      int min_cost=0;
      for(int i=0;i<adj.size();i++){
          int u=findParent(parent,adj[i].second.first);
          int v=findParent(parent,adj[i].second.second);
          int wt=adj[i].first;
          if(u!=v){
              min_cost+=wt;
              Unionset(u,v,parent,rank);
          }
      }
      return min_cost;
    }
};