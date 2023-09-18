class Solution {
public:
    int dp[101];
    int solveRec(vector<int>& nums,int n){
        if(n<0) return 0;
        if(n==0) return nums[0];
        int take=nums[n]+solveRec(nums,n-2);
        int notake=0+solveRec(nums,n-1);
        return max(take,notake);
    }
    int solveMem(vector<int>& nums,int n){
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int take=nums[n]+solveMem(nums,n-2);
        int notake=0+solveMem(nums,n-1);
        return dp[n]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
       // return solveRec(nums,n-1);
        memset(dp,-1,sizeof(dp));
        return solveMem(nums,n-1);
    }
};