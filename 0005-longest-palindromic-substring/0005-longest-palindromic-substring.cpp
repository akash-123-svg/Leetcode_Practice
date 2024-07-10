class Solution {
public:
    int solve(string &s, int i,int j){
        if(i>=j) return 1;
        if(s[i]==s[j]){
            return solve(s,i+1,j-1);
        }
        return 0;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int max_len=INT_MIN;
        int startpoint=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        startpoint=i;
                    }
                }
            }
        }
        return s.substr(startpoint,max_len);
    }
};