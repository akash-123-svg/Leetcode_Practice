class Solution {
public:
    void lpsfind(vector<int>& lps,string s){
        int n=s.size();
        int pre=0;
        int suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }else{
                    pre=lps[pre-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int> lps(m,0);
        lpsfind(lps,needle);
        int first=0,second=0;
        while(first<n && second<m){
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }else{
                if(second==0){
                    //lps[first]=0;
                    first++;
                }else{
                    second=lps[second-1];
                }
            }
        }
        if(second==m){
            return first-second;
        }else{
            return -1;
        }
    }
};