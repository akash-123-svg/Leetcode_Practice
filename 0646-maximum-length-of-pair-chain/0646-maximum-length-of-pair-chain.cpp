class Solution {
public:
     int dp[1001][1001];
    int solveRec(vector<vector<int>>& nums, int currIndex,int prevIndex){
        int n=nums.size();
        if(currIndex==n){
            return 0;
        }
        // take
        int take=0;
        if(prevIndex==-1 || nums[currIndex][0]>nums[prevIndex][1]){
            take=1+solveRec(nums,currIndex+1,currIndex);
        }
        
        // NotTake
        int notTake=0;
        notTake=0+solveRec(nums,currIndex+1,prevIndex);
        
        return max(take,notTake);
    }
    int solveMem(vector<vector<int>>&nums, int currIndex,int prevIndex){
        int n=nums.size();
        if(currIndex==n){
            return 0;
        }
        if(dp[currIndex][prevIndex+1]!=-1) return dp[currIndex][prevIndex+1];
        // take
        int take=0;
        if(prevIndex==-1 || nums[currIndex][0]>nums[prevIndex][1]){
            take=1+solveMem(nums,currIndex+1,currIndex);
        }
        
        // NotTake
        int notTake=0;
        notTake=0+solveMem(nums,currIndex+1,prevIndex);
        
        return dp[currIndex][prevIndex+1]=max(take,notTake);
    }
    int solveTab(vector<vector<int>>&nums){
        int n=nums.size();
        for(int currIndex=n-1;currIndex>=0;currIndex--){
            for(int prevIndex=currIndex-1;prevIndex>=-1; prevIndex--){
                // take
                 int take=0;
                 if(prevIndex==-1 || nums[currIndex][0]>nums[prevIndex][1]){
                 take=1+dp[currIndex+1][currIndex+1];
                 }
                 // NotTake
                 int notTake=0;
                 notTake=0+dp[currIndex+1][prevIndex+1];
                 dp[currIndex][prevIndex+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
    int solveOpt(vector<vector<int>>& nums){
        int n=nums.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int currIndex=n-1;currIndex>=0;currIndex--){
            for(int prevIndex=currIndex-1;prevIndex>=-1; prevIndex--){
                // take
                 int take=0;
                 if(prevIndex==-1 || nums[currIndex][0]>nums[prevIndex][1]){
                 take=1+nextRow[currIndex+1];
                 }
                 // NotTake
                 int notTake=0;
                 notTake=0+nextRow[prevIndex+1];
                 currRow[prevIndex+1]=max(take,notTake);
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
         sort(pairs.begin(),pairs.end());
        //return solveRec(pairs,0,-1);
        // memset(dp,0,sizeof(dp));
         //return solveMem(pairs,0,-1);
         //return solveTab(pairs);
         return solveOpt(pairs);
    }
};