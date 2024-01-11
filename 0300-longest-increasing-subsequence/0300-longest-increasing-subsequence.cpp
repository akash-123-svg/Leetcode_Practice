class Solution {
public:
    int dp[2501][2501];
    int solve(int i,int prev,vector<int>&nums){
        if(i>=nums.size()){
            return 0;
        }
        int take=0,skip=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solve(i+1,i,nums);
        }
        skip=solve(i+1,prev,nums);
        return max(take,skip);
    }
    int solveMem(int i,int prev,vector<int>&nums){
        if(i>=nums.size()){
            return 0;
        }
        if(prev!=-1 && dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int take=0,skip=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solveMem(i+1,i,nums);
        }
        skip=solveMem(i+1,prev,nums);
        if(prev!=-1) dp[i][prev]=max(take,skip);
        
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solveMem(0,-1,nums);
    }
};