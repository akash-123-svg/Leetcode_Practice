class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<=4) return 0;
        int min_diff= nums[n-1]-nums[3]; 
        min_diff=min(min_diff, nums[n-2]-nums[2]); 
        min_diff=min(min_diff, nums[n-3]-nums[1]); 
        min_diff=min(min_diff, nums[n-4]-nums[0]); 
        return min_diff;
    }
};