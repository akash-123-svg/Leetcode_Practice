class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int tot_xor=0;
        for(int i=0;i<n;i++){
            tot_xor^=nums[i];
        }
        int diff=(tot_xor^k);
        return __builtin_popcount(diff);
    }
};