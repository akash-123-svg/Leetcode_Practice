class Solution {
public:
    int solve(int n, vector<int>& cost){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        int min_cost=cost[n]+min(solve(n-1,cost),solve(n-2,cost));
        return min_cost;
    }
    int solveMemo(int n, vector<int>& cost, vector<int>& dp){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        if(dp[n]!=-1) return dp[n];
        dp[n]=cost[n]+min(solveMemo(n-1,cost,dp),solveMemo(n-2,cost,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solveMemo(n-1,cost,dp),solveMemo(n-2,cost,dp));
    }
};