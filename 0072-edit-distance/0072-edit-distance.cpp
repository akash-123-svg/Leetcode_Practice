class Solution {
public:
    int solveRec(string &s1,string &s2,int i,int j){
        // base case
        if(i==s1.length()){
            return s2.length()-j;
        }
        if(j==s2.length()){
            return s1.length()-i;
        }
        int ans=0;
        if(s1[i]==s2[j]){
            return solveRec(s1,s2,i+1,j+1);
        }else{
            // insert
            int insertAns=1+solveRec(s1,s2,i,j+1);
            
            // delete
            int deleteAns=1+solveRec(s1,s2,i+1,j);
            
            // replace
            int replaceAns=1+solveRec(s1,s2,i+1,j+1);
            
            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        return ans;
    }
    int solveMem(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        // base case
        if(i==s1.length()){
            return s2.length()-j;
        }
        if(j==s2.length()){
            return s1.length()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            return solveMem(s1,s2,i+1,j+1,dp);
        }else{
            // insert
            int insertAns=1+solveMem(s1,s2,i,j+1,dp);
            
            // delete
            int deleteAns=1+solveMem(s1,s2,i+1,j,dp);
            
            // replace
            int replaceAns=1+solveMem(s1,s2,i+1,j+1,dp);
            
            ans=min(insertAns,min(deleteAns,replaceAns));
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
       //return solveRec(word1,word2,0,0);
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solveMem(word1,word2,0,0,dp);
    }
};