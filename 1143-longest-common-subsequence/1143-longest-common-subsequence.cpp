class Solution {
public:
    int dp[1001][1001];
    int solve(string &s, string &t,int i,int j){
        if(i==s.length() || j==t.length()){
            return 0;
        }
        int ans=0;
        if(s[i]==t[j]){
            ans=1+solve(s,t,i+1,j+1);
        }else{
            ans=max(solve(s,t,i+1,j),solve(s,t,i,j+1));
        }
        return ans;
    }
    int solveMem(string &s, string &t,int i,int j){
        if(i==s.length() || j==t.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            ans=1+solveMem(s,t,i+1,j+1);
        }else{
            ans=max(solveMem(s,t,i+1,j),solveMem(s,t,i,j+1));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solveMem(text1,text2,0,0);
    }
};