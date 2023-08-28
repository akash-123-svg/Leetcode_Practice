//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
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
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[]){
	    // Code here
	    parent.resize(V);
	    rank.resize(V);
	    for(int i=0;i<V;i++){
	        parent[i]=i;
	        rank[i]=1;
	    }
	    for(int u=0;u<V;u++){
	        for(int &v: adj[u]){
	            if(u<v){
	                int parent_u=find(u);
	                int parent_v=find(v);
	                if(parent_u==parent_v){
	                    return true;
	                }
	                Union(u,v);
	            }
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends