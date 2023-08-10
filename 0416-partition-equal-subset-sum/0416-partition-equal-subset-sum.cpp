class Solution {
public:
    int solveRec(vector<int>& nums,int index,int target,int n){
        if(index>=n) return 0;
        if(target==0) return 1;
        if(target<0) return 0;
        int include=solveRec(nums,index+1,target-nums[index],n);
        int exclude=solveRec(nums,index+1,target,n);
        int ans=(include || exclude);
        return ans;
    }
    int solveMem(vector<int>& nums,int index,int target,int n,vector<vector<int>>&dp){
        if(index>=n) return 0;
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
        int include=solveMem(nums,index+1,target-nums[index],n,dp);
        int exclude=solveMem(nums,index+1,target,n,dp);
        int ans=(include || exclude);
        return dp[index][target]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        int target=sum/2;
        //return solveRec(nums,0,target,n);
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solveMem(nums,0,target,n,dp);
    }
};