class Solution {
public:
    int dp[1001][1001];
    bool solve(string &s,int i,int j){
        if(i>=j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
           return dp[i][j]=solve(s,i+1,j-1);
        }
        return dp[i][j]=0;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};