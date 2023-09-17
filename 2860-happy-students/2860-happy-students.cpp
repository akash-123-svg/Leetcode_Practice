class Solution {
public:
    int countWays(vector<int>& nums) {
     int n = nums.size();
     sort(nums.begin(),nums.end());
        int cnt = 0;
        if(nums[0]!=0){
            cnt++;
        }
        for(int i = 0;i<nums.size();i++){
            if(( nums[i]<(i+1))&&((i+1) == n)){
                cnt++;
            }
            else if((nums[i]<(i+1))&&(((i+1)<n) &&(nums[i+1]>(i+1)))){
                cnt++;
            }
        }
     return cnt;
  }
};