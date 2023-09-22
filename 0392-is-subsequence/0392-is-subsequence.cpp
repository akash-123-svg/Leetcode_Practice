class Solution {
public:
    // // brute force 
    // bool isSubsequence(string s, string t) {
    //    int n=s.length();
    //    int m=t.length();
    //    int i=0,j=0;
    //    while(i<n && j<m){
    //        if(s[i]==t[j]){
    //            i++;
    //            j++;
    //        }else{
    //            j++;
    //        }
    //    }
    //    return i==n;
    // }
     int dp[101][10001];
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
     bool isSubsequence(string s, string t) {
         int n=s.length();
         int m=t.length();
         memset(dp,-1,sizeof(dp));
         if(solveMem(s,t,0,0)==n){
             return true;
         }else{
             return false;
         }
    }
};