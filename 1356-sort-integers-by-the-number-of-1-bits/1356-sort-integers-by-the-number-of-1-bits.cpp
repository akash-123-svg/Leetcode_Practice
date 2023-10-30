class Solution {
public:
    static int cntbits(int n){
        int cnt=0;
        while(n>0){
            cnt++;
            n=n&(n-1);
        }
        return cnt;
    }
    static bool cmp(int a,int b){
        int cntA=cntbits(a);
        int cntB=cntbits(b);
        if(cntA==cntB){
            return a<b;
        }
        return cntA<cntB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};