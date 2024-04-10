class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int n=tops.size();
       vector<int> a1(7,0);
       vector<int> a2(7,0);
       for(int i=0;i<n;i++){
           a1[tops[i]]++;
           a2[bottoms[i]]++;
       }
       vector<int> common(7,0);
       for(int i=0;i<n;i++){
           if(tops[i]==bottoms[i]){
               common[tops[i]]++;
           }
       }
       for(int i=0;i<7;i++){
           if((a1[i]+a2[i]-common[i])==n){
               int res=max(a1[i],a2[i]);
               return n-res;
           }
       }
       return -1;
    }
};