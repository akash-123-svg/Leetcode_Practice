class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
       int n=pref.size();
       vector<int> a(n);
       a[0]=pref[0];
       for(int i=1;i<n;i++){
           a[i]=pref[i]^pref[i-1];
       }
       return a;
    }
};