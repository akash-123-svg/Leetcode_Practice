class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=seats.size();
        int min_moves=0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i=0;i<n;i++){
            min_moves+=abs(seats[i]-students[i]);
        }
        return min_moves;
    }
};