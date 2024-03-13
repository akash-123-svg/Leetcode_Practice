class Solution {
public:
    int pivotInteger(int n) {
       int sumofall=(n*(n+1))/2LL;
       int pivot=sqrt(sumofall);
       int mul=pivot*pivot;
       if(mul==sumofall){
           return pivot;
       }else{
           return -1;
       }
    }
};