class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        map<int,int> mp;
        for(auto it: nums) mp[it]++;
        for(auto it: mp){
            if(it.second>=2) ans.push_back(it.first);
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0) ans.push_back(i);
        }
        return ans;
    }
};