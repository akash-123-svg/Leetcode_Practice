class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        int indices_cnt=0;
        vector<int>expected = heights;
        sort(heights.begin(),heights.end());
        for(int i=0;i<n;i++){
            if(heights[i]!=expected[i]) indices_cnt++;
        }
        return indices_cnt;
    }
};