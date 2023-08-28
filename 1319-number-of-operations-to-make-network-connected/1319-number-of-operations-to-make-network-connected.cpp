class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    void Union(int u,int v){
        u=find(u);
        v=find(v);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]<rank[u]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int component=n;
        for(auto &vec: connections){
            if(find(vec[0])!=find(vec[1])){
                Union(vec[0],vec[1]);
                component--;
            }
        }
        return component-1;
    }
};