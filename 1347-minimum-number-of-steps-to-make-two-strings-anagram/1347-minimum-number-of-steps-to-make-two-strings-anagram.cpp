class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int cnt=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++; 
            mp[t[i]]--; 
        }
        for(auto it: mp){
            if(it.second>0) cnt+=it.second; 
        }
        return cnt; 
    }
};