class Solution {
public:
    int dp[1001][1001];
    int solveRec(string &s,string &t,int i,int j){
        if(i==s.length() || j==t.length()){
            return 0;
        }
        int ans=0;
        if(s[i]==t[j]){
            ans=1+solveRec(s,t,i+1,j+1);
        }else{
            ans=max(solveRec(s,t,i+1,j),solveRec(s,t,i,j+1));
        }
        return ans;
    }
    int solveMem(string &s,string &t,int i,int j){
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
    int solveTab(string &s,string &t){
        memset(dp,0,sizeof(dp));
        int n=s.length();
        int m=t.length();
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(s[i]==t[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        // memset(dp,-1,sizeof(dp));
        // return solveMem(s,t,0,0);
        return solveTab(s,t);
    }
};