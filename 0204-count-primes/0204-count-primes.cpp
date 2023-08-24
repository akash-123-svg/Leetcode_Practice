class Solution {
public:
    int countPrimes(int n) {
       vector<bool> primes(n+1,true);
       primes[0]=primes[1]=false;
       for(int i=2;i*i<=n;i++){
           if(primes[i]==true){
               for(int j=i*i;j<=n;j+=i){
                   primes[j]=false;
               }
           }
       }
       int cnt=0;
       for(int i=2;i<n;i++){
           if(primes[i]==true){
               cnt++;
           }
       }
       return cnt;
    }
};