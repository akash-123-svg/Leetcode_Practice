class Solution {
public:
    vector<string> ans;
    bool isValid(string str){
        int cntsum=0;
        for(char ch:str){
            if(ch=='(') cntsum++;
            else cntsum--;
            if(cntsum<0) return false;
        }
        return cntsum==0;
    }
    void solve(string& s,int n){
        if(s.length() == 2*n){
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }
        
        s.push_back('(');
        solve(s,n);
        s.pop_back();
        
        s.push_back(')');
        solve(s,n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(s,n);
        return ans;
    }
};