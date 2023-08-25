class Solution {
public:
    bool Toposort(unordered_map<int,vector<int>> &adj,int n,vector<int> &indegree){
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop(); 
            for(int &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    cnt++;
                    q.push(v);
                }
            }
        }
        if(cnt==n){  // I was able to finish all the nodes (courses)
            return true;
        }
        return false; // Means there was a cycle and I couldn't complete all courses.
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,false);
        for(auto &vec : prerequisites){
            int a=vec[0];
            int b=vec[1];
            
           // b--->a
           adj[b].push_back(a);
           indegree[a]++;
        }
        return Toposort(adj,n,indegree);
    }
};