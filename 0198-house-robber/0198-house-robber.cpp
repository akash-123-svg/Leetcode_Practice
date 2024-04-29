class Solution {
public:
    int solve(int n, vector<int>& nums){
        if(n<0) return 0;
        if(n==0) return nums[0];
        int take=nums[n]+solve(n-2,nums);
        int notake=0+solve(n-1,nums);
        return max(take,notake);
    }
    int solveMemo(int n,vector<int>& nums,vector<int>& dp){
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int take=nums[n]+solveMemo(n-2,nums,dp);
        int notake=0+solveMemo(n-1,nums,dp);
        return dp[n]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solveMemo(n-1,nums,dp);
    }
};