class Solution {
public:
    // Brite force : - Time O(nlogn), space:- O(1) 
    int solve1(vector<int>& nums){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                cnt=nums[i];
            }
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return solve1(nums);
    }
};