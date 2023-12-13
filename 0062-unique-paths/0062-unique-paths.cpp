class Solution {
public:
    int dp[101][101];
    int solve(int m,int n,int col,int row){
        if(col>=m || row>=n){
            return 0;
        }
        if(col==m-1 && row==n-1){
            return 1;
        }else{
            int x=solve(m,n,col+1,row);
            int y=solve(m,n,col,row+1);
            return (x+y);
        }
    }
    int solveMem(int m,int n,int col,int row){
        if(col>=m || row>=n){
            return 0;
        }
        if(dp[col][row]!=-1){
           return dp[col][row];
        }
        if(col==m-1 && row==n-1){
            return 1;
        }else{
            int x=solveMem(m,n,col+1,row);
            int y=solveMem(m,n,col,row+1);
            return dp[col][row]=(x+y);
        }
    }
    int uniquePaths(int m, int n) {
       memset(dp,-1,sizeof(dp));
       return solveMem(m,n,0,0); 
    }
};