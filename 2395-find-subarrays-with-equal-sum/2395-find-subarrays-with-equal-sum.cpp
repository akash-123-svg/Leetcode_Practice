class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;i++){
            mp[nums[i]+nums[i+1]]++;
            if(mp[nums[i]+nums[i+1]]>=2){
                return true;
            }
        }
        return false;
    }
};