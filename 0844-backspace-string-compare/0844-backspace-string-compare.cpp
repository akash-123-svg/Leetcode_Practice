class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.length();
        int m=t.length();
        stack<int> s1,s2;
        for(int i=0;i<n;i++){
            if(s[i]=='#' && !s1.empty()){
                s1.pop();
            }else if(s[i]!='#'){
                s1.push(s[i]);
            }
        }
        for(int i=0;i<m;i++){
            if(t[i]=='#' && !s2.empty()){
                s2.pop();
            }else if(t[i]!='#'){
                s2.push(t[i]);
            }
        }
        if(s1==s2){
            return true;
        }else{
            return false;
        }
    }
};