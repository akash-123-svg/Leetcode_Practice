class Solution {
public:
    int dp[1001][1001];
    bool checkPred(string &prev,string &curr){
        int n=prev.length();
        int m=curr.length();
        if(n>=m || (m-n)!=1){
            return false;
        }
        int i=0,j=0;
        while(i<n && j<m){
            if(prev[i]==curr[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i==n;
    }
    static bool cmp(string &word1,string &word2){
        return word1.length() < word2.length();
    }
    int LIS(vector<string>& words,int prevIndex,int currIndex){
        int n=words.size();
        if(currIndex==n){
            return 0;
        }
        if(dp[prevIndex+1][currIndex]!=-1){
            return dp[prevIndex+1][currIndex];
        }
        // include
        int take=0;
        if(prevIndex==-1 || checkPred(words[prevIndex],words[currIndex])){
            take=1+LIS(words,currIndex,currIndex+1);
        }
        
        // NotTake
        int notTake=0;
        notTake=0+LIS(words,prevIndex,currIndex+1);
        
        return dp[prevIndex+1][currIndex]=max(take,notTake);
    }
    int longestStrChain(vector<string>& words) {
       memset(dp,-1,sizeof(dp));
       sort(words.begin(),words.end(),cmp);
       return LIS(words,-1,0);
    }
};