class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> ans;
       set<vector<int>> s;
       sort(nums.begin(),nums.end());
       int target=0;
       for(int i=0;i<n;i++){
           int start=i+1;
           int end=n-1;
           while(start<end){
               int sum=nums[i]+nums[start]+nums[end];
               if(sum==target){
                   s.insert({nums[i],nums[start],nums[end]});
                   start++;
                  end--;
               }
               else if(sum<target){
                   start++;
               }else{
                   end--;
               }
           }
       }
       for(auto x: s){
           ans.push_back(x);
       }
       return ans;
    }
};