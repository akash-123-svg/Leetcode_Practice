class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        string res;
        vector<bool> taken(26,false);
        vector<int> lastidx(26);
        
        for(int i=0;i<n;i++){
            char ch=s[i];
            lastidx[ch-'a']=i;
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            
            if(taken[idx]==true)
                continue;
            
            while(res.length()>0 && res.back()>ch && lastidx[res.back()-'a']>i){
                taken[res.back()-'a']=false;
                res.pop_back();
            }
            res.push_back(ch);
            taken[idx]=true;
        }
        return res;
    }
};