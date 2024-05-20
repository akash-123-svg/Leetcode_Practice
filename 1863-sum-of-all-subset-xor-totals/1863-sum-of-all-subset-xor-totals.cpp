class Solution {
public:
    int solve(int cur, vector<int> &nums, int x){
        if(cur==nums.size()){
            return x;
        }
        int take = solve(cur+1,nums,nums[cur]^x);
        int notTake= solve(cur+1,nums,x);
        return take+notTake;
    }
    int subsetXORSum(vector<int>& nums) {
       return solve(0,nums,0); 
    }
};