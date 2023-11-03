class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>res(n+1,vector<int>(m+1,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        
        res[0][0]=0;
        pq.push({0,{0,0}});
        
        auto isSafe=[&](int x,int y){
            return (x>=0 && x<n && y>=0 && y<m);
        };
        
        while(!pq.empty()){
            int diff=pq.top().first;
            pair<int,int> coords=pq.top().second;
            int x=coords.first;
            int y=coords.second;
            pq.pop();
            
            for(auto &dir: dirs){
                int newx=x+dir[0];
                int newy=y+dir[1];
                
                if(isSafe(newx,newy)){
                    
                int absDiff=abs(heights[x][y]-heights[newx][newy]);
                int maxxDiff=max(diff,absDiff);
                
                if(res[newx][newy] > maxxDiff){
                    res[newx][newy]=maxxDiff;
                    pq.push({maxxDiff,{newx,newy}});
                 }
              }
            }
        }
        return res[n-1][m-1];
    }
};