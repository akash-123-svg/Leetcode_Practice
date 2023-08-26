class Solution {
public:
    vector<int> TopoSort(unordered_map<int,vector<int>> &adj,int n,vector<int> &indegree){
        queue<int> q;
        int cnt=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    ans.push_back(v);
                    cnt++;
                    q.push(v);
                }
            }
        }
        if(cnt==n){
            return ans;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        
        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];
            
            // b--->a
            adj[b].push_back(a);
            
            // arrow 'a' me ja raha hai
            indegree[a]++;
        }
        return TopoSort(adj,n,indegree);
    }
};