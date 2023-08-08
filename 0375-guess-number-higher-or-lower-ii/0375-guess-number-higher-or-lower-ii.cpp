class Solution {
public:
    int dp[202][202];
    int solveRec(int start,int end){
        if(start>=end) return 0;
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans,i+max(solveRec(start,i-1),solveRec(i+1,end)));
        }
        return ans;
    }
    int solveMem(int start,int end){
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans,i+max(solveMem(start,i-1),solveMem(i+1,end)));
        }
        return dp[start][end]=ans;
    }
    int solveTab(int n){
        for(int start=n;start>=1;start--){
            for(int end=start;end<=n;end++){
                if(start==end){
                    continue;
                }else{
                    int ans=INT_MAX;
                    for(int i=start;i<=end;i++){
                        ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end]=ans;
                }
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
       // return solveRec(1,n);
       memset(dp,0,sizeof(dp));
       //return solveMem(1,n);
       return solveTab(n);
    }
};