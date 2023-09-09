class Solution {
public:
    int solve(vector<int>&nums,int target){
         if(target==0) return 1;
         if(target<0) return 0;
         int sum=0;
         for(int i=0;i<nums.size();i++){
             sum+=solve(nums,target-nums[i]);
         }
         return sum;
    }
    int solveMem(vector<int>&nums,int target,vector<int>&dp){
         if(target==0) return 1;
         if(target<0) return 0;
         if(dp[target]!=-1) return dp[target];
         int sum=0;
         for(int i=0;i<nums.size();i++){
           if(target>=nums[i]) sum+=solveMem(nums,target-nums[i],dp);
         }
         return dp[target]=sum;
    }
    int solveTab(vector<int>&nums,int tar){
         vector<int> dp(tar+1,0);
         dp[0]=1;
         for(int i=1;i<=tar;i++){
           for(int j=0;j<nums.size();j++){
               if(i>=nums[j]){
                 dp[i]+=dp[i-nums[j]];
               }
           }
         }
         return dp[tar];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solveMem(nums,target,dp);
       // return solve(nums,target);
       // return solveTab(nums,target);
    }
};