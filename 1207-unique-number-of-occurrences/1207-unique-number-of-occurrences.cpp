class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       int n=arr.size();
       map<int,int> mp;
       set<int> s;
       for(int i=0;i<n;i++){
           mp[arr[i]]++;
       }
       for(auto it: mp){
           s.insert(it.second);
       }
       if(s.size()==mp.size()){
           return true;
       }else{
           return false;
       }
    }
};