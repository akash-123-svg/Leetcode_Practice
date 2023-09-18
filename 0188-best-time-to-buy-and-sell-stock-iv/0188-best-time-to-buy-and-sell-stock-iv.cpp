class Solution {
public:
    int dp[101][1001][2];
    int solveRec(int Ktrans,vector<int>& prices,int index,int buy){
        if(index>=prices.size()){
            return 0;
        }
        if(Ktrans==0){
            return 0;
        }
        int max_profit=0;
        if(buy==1){
            int buykaro=(-prices[index])+solveRec(Ktrans,prices,index+1,0);
            int skipkaro=0+solveRec(Ktrans,prices,index+1,1);
            max_profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=(prices[index])+solveRec(Ktrans-1,prices,index+1,1);
            int skipkaro=0+solveRec(Ktrans,prices,index+1,0);
            max_profit=max(sellkaro,skipkaro);
        }
        return max_profit;
    }
    int solveMem(int Ktrans,vector<int>& prices,int index,int buy){
        if(index>=prices.size()){
            return 0;
        }
        if(Ktrans==0){
            return 0;
        }
        if(dp[Ktrans][index][buy]!=-1){
            return dp[Ktrans][index][buy];
        }
        int max_profit=0;
        if(buy==1){
            int buykaro=(-prices[index])+solveMem(Ktrans,prices,index+1,0);
            int skipkaro=0+solveMem(Ktrans,prices,index+1,1);
            max_profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=(prices[index])+solveMem(Ktrans-1,prices,index+1,1);
            int skipkaro=0+solveMem(Ktrans,prices,index+1,0);
            max_profit=max(sellkaro,skipkaro);
        }
        return dp[Ktrans][index][buy]=max_profit;
    }
    int solveTab(int k,vector<int>& prices){
        int n=prices.size();
        memset(dp,0,sizeof(dp));
        for(int Ktrans=1;Ktrans<=k;Ktrans++){
            for(int index=n-1;index>=0;index--){
                for(int buy=0;buy<=1;buy++){
                    int max_profit=0;
                    if(buy==1){
                        int buykaro=(-prices[index])+dp[Ktrans][index+1][0];
                        int skipkaro=0+dp[Ktrans][index+1][1];
                        max_profit=max(buykaro,skipkaro);
                    }else{
                        int sellkaro=(prices[index])+dp[Ktrans-1][index+1][1];
                        int skipkaro=0+dp[Ktrans][index+1][0];
                        max_profit=max(sellkaro,skipkaro);
                    }
                    dp[Ktrans][index][buy]=max_profit;
                }
            }
        }
        return dp[k][0][1];
    }
    int maxProfit(int k, vector<int>& prices) {
       //return solveRec(k,prices,0,1); 
       // memset(dp,-1,sizeof(dp));
       // return solveMem(k,prices,0,1);
        return solveTab(k,prices);
    }
};