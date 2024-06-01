class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int res=0;
        for(int i=0;i<n-1;i++){
            int ans=abs(s[i]-s[i+1]);
            res+=ans;
        }
        return res;
    }
};