class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        long long max_score=0;
        priority_queue<int> pq(nums.begin(),nums.end());
        while(k--){
            int val=pq.top(); 
            pq.pop();
            max_score+=val;
            val=ceil(val/3.0);
            pq.push(val);
        }
        return max_score;
    }
};