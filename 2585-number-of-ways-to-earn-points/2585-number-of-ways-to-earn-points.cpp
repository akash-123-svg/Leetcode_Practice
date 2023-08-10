class Solution {
public:
    int mod=1e9+7;
    int solveRec(int target,vector<vector<int>>& types,int index,int n){
        if(target==0) return 1;
        if(index>=n || target<0) return 0;
        int countOfques=types[index][0];
        int quesPerMarkes=types[index][1];
        int ans=0;
        for(int choice=0;choice<=countOfques;choice++){
            int total=choice*quesPerMarkes;
            ans+=solveRec(target-total,types,index+1,n)%mod;
        }
        return ans%mod;
    }
    int solveMem(int target,vector<vector<int>>& types,int index,int n,vector<vector<long long>>&dp){
        if(target==0) return 1;
        if(index>=n || target<0) return 0;
        if(dp[target][index]!=-1) return dp[target][index];
        int countOfques=types[index][0];
        int quesPerMarkes=types[index][1];
        long long ans=0;
        for(int choice=0;choice<=countOfques;choice++){
            long long total=choice*quesPerMarkes;
            ans+=solveMem(target-total,types,index+1,n,dp)%mod;
        }
        return dp[target][index]=ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        //return solveRec(target,types,0,types.size())%mod;
        vector<vector<long long>>dp(target+1,vector<long long>(types.size()+1,-1));
        return solveMem(target,types,0,types.size(),dp)%mod;
    }
};