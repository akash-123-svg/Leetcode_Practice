class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.length();
        int m=t.length();
        char sum1=0;
        char sum2=0;
        for(int i=0;i<n;i++){
            sum1+=s[i];
        }
        for(int j=0;j<m;j++){
            sum2+=t[j];
        }
        return char(sum2-sum1);
    }
};