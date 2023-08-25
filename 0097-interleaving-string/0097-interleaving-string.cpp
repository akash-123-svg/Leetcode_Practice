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
    // Method 1:- using 3D-DP, Time:- O(l*m*n)
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
    // Method 2: using 2D-DP, Time:- O(l*n)
    int dp1[101][101];
    bool solveMem1(int i,int j,string &s1,string &s2,string &s3){
        int l=s1.length();
        int m=s2.length();
        int n=s3.length();
        if(i==l && j==m && i+j==n){  // k is replace with i+j thats it..
            return true;
        }
        if(i+j>=n){
            return false;
        }
        if(dp1[i][j]!=-1) return dp1[i][j];
        bool res=false;
        if(s1[i]==s3[i+j]){
            res=solveMem1(i+1,j,s1,s2,s3);
        }
        if(res==true){
            return dp1[i][j]=true;
        }
        if(s2[j]==s3[i+j]){
            res=solveMem1(i,j+1,s1,s2,s3);
        }
        return dp1[i][j]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l=s1.length();
        int m=s2.length();
        int n=s3.length();
        //memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        return solveMem1(0,0,s1,s2,s3);
    }
};