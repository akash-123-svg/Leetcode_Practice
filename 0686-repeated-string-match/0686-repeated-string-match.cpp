class Solution {
public:
    void lpsfind(vector<int>&lps,string s){
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
    int kmp_match(string haystack, string needle) {
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
            return 1;
        }else{
            return 0;
        }
    }
    int repeatedStringMatch(string a, string b) {
       if(a==b) return 1;
       vector<int> lps(b.size(),0);
       int repeat=1;
       string temp=a;
       while(temp.size()<b.size()){
           temp+=a;
           repeat++;
       }
       if(kmp_match(temp,b)==1){
           return repeat;
       }else if(kmp_match(temp+a,b)==1){
           return repeat+1;
       }else{
           return -1;
       }
    }
};