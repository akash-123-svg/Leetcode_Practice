class Solution {
public:
    bool pal(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    int solveRec(string &s, int i,int j){
        //if(i<=j) return 0;
        if(pal(s,i,j)){
            return 0;
        }
        int mincuts=INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(pal(s,i,k)){
                int cuts=1+solveRec(s,k+1,j);
                mincuts=min(mincuts,cuts);
            }
        }
        return mincuts;
    }
    int solveMem(string &s, int i,int j,vector<vector<int>>&dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(pal(s,i,j)){
            return dp[i][j]=0;
        }
        int mincuts=INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(pal(s,i,k)){
                int cuts=1+solveMem(s,k+1,j,dp);
                mincuts=min(mincuts,cuts);
            }
        }
        return dp[i][j]=mincuts;
    }
    int minCut(string s) {
        int n=s.length();
        //return solveRec(s,0,n-1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMem(s,0,n-1,dp);
    }
};