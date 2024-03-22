class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        vector<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push_back(')');
            }else if(s[i]=='{'){
                st.push_back('}');
            }else if(s[i]=='['){
                st.push_back(']');
            }else{
                if((st.empty()) || (s[i]!=st[st.size()-1]))
                    return false;
                    st.pop_back();
            }
        }
        return st.empty();
    }
};