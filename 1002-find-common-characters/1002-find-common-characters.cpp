class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string> res;
        vector<int> min_freq(26,INT_MAX);
        for(auto& x: words){
            vector<int> freq(26,0);
            for(char &c: x){
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                min_freq[i]=min(min_freq[i],freq[i]);
            }
        }
        for(int i=0;i<26;i++){
            while(min_freq[i]>0){
                res.push_back(string(1,i+'a'));
                min_freq[i]--;
            }
        }
        return res;
    }
};