class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int depth=0;
        int maxx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
            }else if(s[i]==')'){
                depth--;
            }
            maxx=max(depth,maxx);
        }
        return maxx;
    }
};