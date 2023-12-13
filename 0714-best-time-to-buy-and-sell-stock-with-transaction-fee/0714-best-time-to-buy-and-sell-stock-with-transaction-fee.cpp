class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>& prices,int fee,int index,int buy){
        if(index>=prices.size()){
            return 0;
        }
        int max_profit=0;
        if(buy==1){
            int buykaro=(-prices[index])+solve(prices,fee,index+1,0);
            int skipkaro=0+solve(prices,fee,index+1,1);
            max_profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=(prices[index])+solve(prices,fee,index+1,1)-fee;
            int skipkaro=0+solve(prices,fee,index+1,0);
            max_profit=max(sellkaro,skipkaro);
        }
        return max_profit;
    }
    int solveMem(vector<int>& prices,int fee,int index,int buy){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int max_profit=0;
        if(buy==1){
            int buykaro=(-prices[index])+solveMem(prices,fee,index+1,0);
            int skipkaro=0+solveMem(prices,fee,index+1,1);
            max_profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=(prices[index])+solveMem(prices,fee,index+1,1)-fee;
            int skipkaro=0+solveMem(prices,fee,index+1,0);
            max_profit=max(sellkaro,skipkaro);
        }
        return dp[index][buy]=max_profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return solveMem(prices,fee,0,1);
    }
};