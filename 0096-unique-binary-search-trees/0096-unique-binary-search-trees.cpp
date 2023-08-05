class Solution {
public:
    int solveRec(int n){
        if(n<=1) return 1;
        int sum=0;
        for(int i=1;i<=n;i++){  // think i as a root node
            sum+=solveRec(i-1)*solveRec(n-i);
        }
        return sum;
    }
    int numTrees(int n) {
        return solveRec(n);
    }
};