class Solution {
public:
    int dp[101][101];
    int solveRec(int col,int row,int m,int n){
        if(col>=m || row>=n){
            return 0;
        }else if(col==m-1 && row==n-1){
            return 1;
        }else{
            int x=solveRec(col+1,row,m,n);
            int y=solveRec(col,row+1,m,n);
            return (x+y);
        }
    }
    int solveMem(int col,int row,int m,int n){
        if(col>=m || row>=n){
            return 0;
        }if(col==m-1 && row==n-1){
            return 1;
        }if(dp[col][row]!=-1) return dp[col][row];
        else{
            int x=solveMem(col+1,row,m,n);
            int y=solveMem(col,row+1,m,n);
            return dp[col][row]=(x+y);
        }
    }
    int uniquePaths(int m, int n) {
       // return solveRec(0,0,m,n);
        memset(dp,-1,sizeof(dp));
        return solveMem(0,0,m,n);
    }
};