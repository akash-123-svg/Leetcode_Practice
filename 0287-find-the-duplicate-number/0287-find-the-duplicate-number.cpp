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
    
    // Opti app:- Time :- O(n), space:- O(1);
    int solve2(vector<int>& nums){
       int slow=nums[0];
       int fast=nums[0];
       do{
           slow=nums[slow];
           fast=nums[nums[fast]];
       }
       while(slow!=fast); 
          slow=nums[0];
       while(slow!=fast){
           slow=nums[slow];
           fast=nums[fast];
       }
       return slow;
    }
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return solve1(nums);
        return solve2(nums);
    }
};