class Solution {
public:
    bool static cmp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }else{
            return a[1]<b[1];
        }
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int durations=0;
        priority_queue<int> pq;
        for(auto &x: courses){
            durations+=x[0];
            pq.push(x[0]);
            if(durations>x[1]){
                int f=pq.top();
                pq.pop();
                durations-=f;
            }
        }
        return pq.size();
    }
};