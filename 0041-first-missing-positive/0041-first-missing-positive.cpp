class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]==cnt) cnt++;
        }
        return cnt;
    }
};