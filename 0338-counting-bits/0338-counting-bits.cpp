class Solution {
public:
    vector<int> countBits(int n) {
        // Method 1:- using built-in function, Time:- O(nlogn)
        // vector<int> ans(n+1);
        // for(int i=1;i<=n;i++){
        //     ans[i]=__builtin_popcount(i);
        // }
        // return ans;
        
        // Method 2: without using any built-in function, Time:- O(n)
         vector<int> ans(n+1);
         ans[0]=0;
         for(int i=1;i<=n;i++){
             if(i%2!=0){
                 ans[i]=ans[i/2]+1;
             }else{
                 ans[i]=ans[i/2];
             }
         }
         return ans;
    }
};