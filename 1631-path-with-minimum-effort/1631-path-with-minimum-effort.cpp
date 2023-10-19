class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions={{-1,0},{0,-1},{0,1},{1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>>res(n+1,vector<int>(m+1,INT_MAX));
        res[0][0]=0;
        pq.push({0,{0,0}});
        
        auto isSafe = [&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        while(!pq.empty()){
            int diff=pq.top().first;
            pair<int,int> coord=pq.top().second;
            int x=coord.first;
            int y=coord.second;
            pq.pop();
            
            for(auto &dir : directions){
                int newx=x+dir[0];
                int newy=y+dir[1];
                
                if(isSafe(newx,newy)){
                    int absDiff=abs(heights[x][y]-heights[newx][newy]);
                    int maxDiff=max(diff,absDiff);
                    if(maxDiff < res[newx][newy]){
                        res[newx][newy]=maxDiff;
                        pq.push({maxDiff,{newx,newy}});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};