class Solution {
public:
    vector<int>Topo(int n, vector<vector<int>>& prerequisites, vector<int>& indegree, unordered_map<int,vector<int>>& adj){
        queue<int> q;
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            
            for(auto &x: adj[f]){
                indegree[x]--;
                if(indegree[x]==0){
                    cnt++;
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        if(cnt==n){
            return ans;
        }else{
            return {};
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> ans;
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto &vec: prerequisites){
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return Topo(n,prerequisites,indegree, adj);
    }
};