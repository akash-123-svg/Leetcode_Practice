class Solution {
public:
    // Approach 1:- Recursion 
    double solveRec(int poured, int i, int j){
        if(i<0 || j<0 || i<j){
            return 0.0;
        }
        if(i==0 && j==0) // we reached on top
            return poured;
        
        double up_left=(solveRec(poured,i-1,j-1)-1)/2.0;
        double up_right=(solveRec(poured,i-1,j)-1)/2.0;
        
        if(up_left<0){
            up_left=0.0;
        }
        if(up_right<0){
            up_right=0.0;
        }
        return up_left + up_right;
        
    }
    // Approach 2:- Recursion + Memoization 
    double dp[101][101];
    double solveMem(int poured, int i, int j){
        if(i<0 || j<0 || i<j){
            return 0.0;
        }
        if(i==0 && j==0) // we reached on top
            return poured;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        double up_left=(solveMem(poured,i-1,j-1)-1)/2.0;
        double up_right=(solveMem(poured,i-1,j)-1)/2.0;
        
        if(up_left<0){
            up_left=0.0;
        }
        if(up_right<0){
            up_right=0.0;
        }
        return dp[i][j]= up_left + up_right;
        
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        return min(1.0,solveMem(poured,query_row,query_glass));
    }
};