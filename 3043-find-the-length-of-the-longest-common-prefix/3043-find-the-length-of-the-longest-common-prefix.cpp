class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            string val=to_string(arr1[i]);
            string pre;
            for(auto ch: val){
                pre+=ch;
                st.insert(pre); // st("1","10","100")
            }
        }
        int len_cp=0;
        int m=arr2.size();
        for(int i=0;i<m;i++){
            string val=to_string(arr2[i]);
            string pre;
            for(auto ch: val){
                pre+=ch;       
                if(st.count(pre)) len_cp=max(len_cp,(int) pre.size());
            }
        }
        return len_cp;
    }
};