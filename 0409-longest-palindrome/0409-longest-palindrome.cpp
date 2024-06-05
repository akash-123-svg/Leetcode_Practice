class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        map<char,int> mp;
        int evecnt=0, oddcnt=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            
            if(mp[s[i]]%2==1){
                oddcnt++;
            }else{
                oddcnt--;                                                       
            }
        }
        if(oddcnt>1){
            return n-oddcnt+1;
        }else{
            return n;
        }
        
    }
};