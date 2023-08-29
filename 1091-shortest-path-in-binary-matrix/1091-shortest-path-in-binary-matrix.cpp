class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions={{1,1},{-1,1},{1,-1},{-1,-1},{0,1},{1,0},{0,-1},{-1,0}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(n==0 || m==0 || grid[0][0]!=0){
            return -1;
        }
        auto isSafe=[&](int x,int y){
           if(x>=0 && x<m && y>=0 && y<n){
               return true;
           }
            return false;
        };
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        
        // apply dijkstra algorithm here
        priority_queue<P,vector<P>,greater<P>> pq;
        
        pq.push({0,{0,0}});
        res[0][0]=0;
        
        while(!pq.empty()){
            int d=pq.top().first;
            pair<int,int> node=pq.top().second;
            int new_x=node.first;
            int new_y=node.second;
            pq.pop();
            
            for(auto dir : directions){
                int x_=new_x+dir[0];
                int y_=new_y+dir[1];
                
                int dist=1;
                
                if(isSafe(x_,y_) && grid[x_][y_]==0 && d+dist < res[x_][y_]){
                    pq.push({d+dist,{x_,y_}});
                    res[x_][y_]=d+dist; 
                }
            }
        }
        if(res[m-1][n-1]==INT_MAX){
            return -1;
        }else{
            return res[m-1][n-1]+1;
        }
    }
};