class Solution {
public:
    int dp[101][101][201];
    bool solveRec(int i,int j,int k,string &s1,string &s2,string &s3){
        int l=s1.length();
        int m=s2.length();
        int n=s3.length();
        if(i==l && j==m && k==n){
            return true;
        }
        if(k>=n){
            return false;
        }
        bool res=false;
        if(s1[i]==s3[k]){
            res=solveRec(i+1,j,k+1,s1,s2,s3);
        }
        if(res==true){
            return true;
        }
        if(s2[j]==s3[k]){
            res=solveRec(i,j+1,k+1,s1,s2,s3);
        }
        return res;
    }
    bool solveMem(int i,int j,int k,string &s1,string &s2,string &s3){
        int l=s1.length();
        int m=s2.length();
        int n=s3.length();
        if(i==l && j==m && k==n){
            return true;
        }
        if(k>=n){
            return false;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool res=false;
        if(s1[i]==s3[k]){
            res=solveMem(i+1,j,k+1,s1,s2,s3);
        }
        if(res==true){
            return dp[i][j][k]=true;
        }
        if(s2[j]==s3[k]){
            res=solveMem(i,j+1,k+1,s1,s2,s3);
        }
        return dp[i][j][k]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l=s1.length();
        int m=s2.length();
        int n=s3.length();
        memset(dp,-1,sizeof(dp));
        return solveMem(0,0,0,s1,s2,s3);
    }
};