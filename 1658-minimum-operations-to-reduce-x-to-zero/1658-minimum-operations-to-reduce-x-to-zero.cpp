class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum-x;
        if(target==0){
            return n;
        }
        int maxx=INT_MIN;
        int start=0;
        int end=0;
        int currsum=0;
        while(end<n){
            currsum+=nums[end];
            end++;
            while(start<end && currsum>target){
                currsum-=nums[start];
                start++;
            }
            if(currsum==target){
                maxx=max(maxx,end-start);
            }
        }
        if(maxx==INT_MIN){
            return -1;
        }
        return n-maxx;
    }
};