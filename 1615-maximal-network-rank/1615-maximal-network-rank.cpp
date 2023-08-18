class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> v(n);
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]].insert(roads[i][1]);
            v[roads[i][1]].insert(roads[i][0]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=v[i].size()+v[j].size();
                if(v[i].find(j)!=v[j].find(i)){
                    curr--;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};