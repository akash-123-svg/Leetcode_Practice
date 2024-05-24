class Solution {
public:
    int res=0;
    void solve(int index, vector<int>& nums, int k,unordered_map<int,int> &mp){
        if(index>=nums.size()){
            res++;
            return;
        }
        // noTake
        solve(index+1,nums,k,mp);
        
        // Take
        if(!mp[nums[index]-k] && !mp[nums[index]+k]){
            mp[nums[index]]++; // do
            solve(index+1,nums,k,mp); // explore
            mp[nums[index]]--; // undo
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        solve(0,nums,k,mp);
        
        return res-1;
    }
};