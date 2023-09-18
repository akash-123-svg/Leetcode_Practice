class Solution {
public:
    int dp[30001][2];
    int solveRec(vector<int>&prices,int index,int buy){
        if(index>=prices.size()){
            return 0;
        }
        int max_profit=0;
        if(buy==1){
            int buykaro=(-prices[index])+solveRec(prices,index+1,0);
            int skipkaro=0+solveRec(prices,index+1,1);
            max_profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=(prices[index])+solveRec(prices,index+1,1);
            int skipkaro=0+solveRec(prices,index+1,0);
            max_profit=max(sellkaro,skipkaro);
        }
        return max_profit;
    }
    int solveMem(vector<int>&prices,int index,int buy){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int max_profit=0;
        if(buy==1){
            int buykaro=(-prices[index])+solveMem(prices,index+1,0);
            int skipkaro=0+solveMem(prices,index+1,1);
            max_profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=(prices[index])+solveMem(prices,index+1,1);
            int skipkaro=0+solveMem(prices,index+1,0);
            max_profit=max(sellkaro,skipkaro);
        }
        return dp[index][buy]=max_profit;
    }
    int solveTab(vector<int>&prices){
         int n=prices.size();
         memset(dp,0,sizeof(dp));
         for(int index=n-1;index>=0;index--){
             for(int buy=0;buy<=1;buy++){
                 int max_profit=0;
                 if(buy==1){
                   int buykaro=(-prices[index])+dp[index+1][0];
                   int skipkaro=0+dp[index+1][1];
                   max_profit=max(buykaro,skipkaro);
                  }else{
                   int sellkaro=(prices[index])+dp[index+1][1];
                   int skipkaro=0+dp[index+1][0];
                   max_profit=max(sellkaro,skipkaro);
                 }
                dp[index][buy]=max_profit;
             }
         }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        //return solveRec(prices,0,1);
        // memset(dp,-1,sizeof(dp));
        // return solveMem(prices,0,1);
        return solveTab(prices);
    }
};