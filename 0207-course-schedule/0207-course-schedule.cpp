class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto &vec: pre){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        int cnt=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int sz=q.front();
            q.pop();
            
            for(auto &vec: adj[sz]){
                indegree[vec]--;
                if(indegree[vec]==0){
                    q.push(vec);
                    cnt++;
                }
            }
        }
        if(cnt==n) return true;
        else return false;
    }
};