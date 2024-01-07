class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        set<int> s,s1,s2;
        for(int i=0;i<n;i++){
            s1.insert(nums1[i]);
            s.insert(nums1[i]);
        }
        for(int i=0;i<m;i++){
            s2.insert(nums2[i]);
            s.insert(nums2[i]);
        }
        int x=s1.size(),y=s2.size(),z=s.size();
        int maxx=min(z,min(n/2,x)+min(n/2,y));
        return maxx;
        
    }
};