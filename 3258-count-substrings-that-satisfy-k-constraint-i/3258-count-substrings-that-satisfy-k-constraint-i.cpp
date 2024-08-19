class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        
//         // Approach 1:- Brute force
//         int n=s.length();
//         int res=0;
//         for(int i=0;i<n;i++){
            
//             int cnt0=0;
//             int cnt1=0;
            
//             for(int j=i;j<n;j++){
                
//                 if(s[j]=='0') cnt0++;
//                 else cnt1++;
                
//                 if(cnt0<=k || cnt1<=k) res++;
//             }
//         }
//         return res;
        
        // Approach 2:- Sliding Windows
        
        int n=s.length();
        int res=0;
        
        int i=0;
        int j=0;
        
        int cnt0=0;
        int cnt1=0;
        
        while(j<n){
            if(s[j]=='0') {
                cnt0++;
            }else {
                cnt1++;
            }
            while(cnt0>k && cnt1>k){
                if(s[i]=='0'){
                    cnt0--;
                }else{
                    cnt1--;
                }
                i++;
            }
            res+=(j-i+1);
            j++;
        }
        return res;
    }
};