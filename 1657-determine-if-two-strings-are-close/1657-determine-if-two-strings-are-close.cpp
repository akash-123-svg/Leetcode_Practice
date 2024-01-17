class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n!=m) return false;
        //map<char,int> m1,m2;
        vector<int> m1(26,0),m2(26,0);
        set<int> s1,s2;
        for(int i=0;i<n;i++){
            m1[word1[i]-'a']++;
            s1.insert(word1[i]);
            //cout<<s1.size()<<" ";
        }
        for(int i=0;i<m;i++){
            m2[word2[i]-'a']++;
            s2.insert(word2[i]);
            //cout<<s2.size()<<" ";
        }
        // for(auto it: m1){
        //     s1.insert(it.second);
        // }
        // for(auto it: m2){
        //     s2.insert(it.second);
        // }
        sort(m1.begin(),m1.end());
        sort(m2.begin(),m2.end());
        if(m1==m2 && s1==s2){
            return true;
        }else{
            return false;
        }
    }
};