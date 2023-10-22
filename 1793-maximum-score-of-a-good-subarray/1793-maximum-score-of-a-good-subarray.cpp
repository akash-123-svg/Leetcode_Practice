class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        stack<pair<int,int>> s;
        vector<int> left;
        for(int i=0;i<n;i++){
            if(s.size()==0){
                left.push_back(-1);
            }else if(s.size()>0 && s.top().first<nums[i]){
                left.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=nums[i]){
                while(s.size()>0 && s.top().first>=nums[i]){
                    s.pop();
                }
                if(s.size()==0){
                    left.push_back(-1);
                }else{
                    left.push_back(s.top().second);
                }
            }
            s.push({nums[i],i});
        }
        stack<pair<int,int>> s2;
        vector<int> right;
        for(int i=n-1;i>=0;i--){
            if(s2.size()==0){
                right.push_back(n);
            }else if(s2.size()>0 && s2.top().first<nums[i]){
                right.push_back(s2.top().second);
            }else if(s2.size()>0 && s2.top().first>=nums[i]){
                while(s2.size()>0 && s2.top().first>=nums[i]){
                    s2.pop();
                }
                if(s2.size()==0){
                    right.push_back(n);
                }else{
                    right.push_back(s2.top().second);
                }
            }
            s2.push({nums[i],i});
        }
        reverse(right.begin(),right.end());
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            if(left[i]<k && right[i]>k){
             int area=(right[i]-left[i]-1)*nums[i];
             maxx=max(maxx,area);
            }
        }
        return maxx;
    }
};