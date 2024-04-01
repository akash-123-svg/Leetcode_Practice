class Solution {
public:
    bool isPalindrome(int x) {
       string s;
       s=to_string(x);
       string s2=s;
       reverse(s2.begin(),s2.end());
       if(s2==s) return true;
       else return false;
    }
};