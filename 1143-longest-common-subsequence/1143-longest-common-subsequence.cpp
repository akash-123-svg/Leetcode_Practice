class Solution {
public:
    int dp[1001][1001];
    int solveRec(string &text1,string &text2,int i,int j){
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+solveRec(text1,text2,i+1,j+1);
        }else{
            ans=max(solveRec(text1,text2,i+1,j),solveRec(text1,text2,i,j+1));
        }
        return ans;
    }
    int solveMem(string &text1,string &text2,int i,int j){
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+solveMem(text1,text2,i+1,j+1);
        }else{
            ans=max(solveMem(text1,text2,i+1,j),solveMem(text1,text2,i,j+1));
        }
        return dp[i][j]=ans;
    }
    int solveTab(string &text1,string &text2){
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+dp1[i+1][j+1];
                }else{
                    ans=max(dp1[i][j+1],dp1[i+1][j]);
                }
                dp1[i][j]=ans;
            }
        }
        return dp1[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        //return solveRec(text1,text2,0,0);
        // memset(dp,-1,sizeof(dp));
        // return solveMem(text1,text2,0,0);
        return solveTab(text1,text2);
    }
};