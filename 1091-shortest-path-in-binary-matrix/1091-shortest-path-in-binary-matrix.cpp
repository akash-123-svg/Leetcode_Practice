class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions={{1,1},{-1,1},{1,-1},{-1,-1},{0,1},{1,0},{0,-1},{-1,0}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0 || m==0 || grid[0][0]!=0){
            return -1;
        }
        auto isSafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int d=pq.top().first;
            pair<int,int>cord=pq.top().second;
            int newx=cord.first;
            int newy=cord.second;
            pq.pop();
            
            for(auto &dir : directions){
                int x_=newx+dir[0];
                int y_=newy+dir[1];
                int wt=1;
                if(isSafe(x_,y_) && grid[x_][y_]==0 && d+wt < ans[x_][y_]){
                    ans[x_][y_]=d+wt;
                    pq.push({d+wt,{x_,y_}});
                }
            }
        }
        if(ans[n-1][m-1]==INT_MAX){
            return -1;
        }else{
            return ans[n-1][m-1]+1;
        }
    }
};