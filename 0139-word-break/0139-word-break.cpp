class Solution {
public:
    int dp[301];
    int solveRec(string s,int index,set<string>& wordDict){
        if(index==s.length()) return 1;
        string t="";
        for(int j=index;j<s.length();j++){
            t+=s[j];
            if(wordDict.find(t)!=wordDict.end()){
                if(solveRec(s,j+1,wordDict)) return 1;
            }
        }
        return 0;
    }
    int solveMem(string s,int index,set<string>& wordDict){
        if(index==s.length()) return 1;
        string t="";
        if(dp[index]!=-1) return dp[index];
        for(int j=index;j<s.length();j++){
            t+=s[j];
            if(wordDict.find(t)!=wordDict.end()){
               if(solveMem(s,j+1,wordDict)) return dp[index]=1;
            }
        }
        return dp[index]=0;
    }
    int solveTab(string s,vector<string>& wordDict){
        int n=s.length();
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        set<string> st;
        for(auto x:wordDict){
            st.insert(x);
        }
        for(int index=n-1;index>=0;index--){
        string t="";
        for(int j=index;j<n;j++){
            t+=s[j];
            if(st.find(t)!=st.end()){
              if(dp[j+1]) dp[index]=1;
             }
          }
       }
       return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solveTab(s,wordDict);
    }
};