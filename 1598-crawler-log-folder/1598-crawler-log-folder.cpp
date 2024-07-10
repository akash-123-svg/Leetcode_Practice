class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int min_op=0;
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                min_op--;
                if(min_op<0){
                    min_op=0;
                }
            }else if(logs[i]=="./"){
                continue;
            }else{
                min_op++;
            }
        }
        return min_op;
    }
};