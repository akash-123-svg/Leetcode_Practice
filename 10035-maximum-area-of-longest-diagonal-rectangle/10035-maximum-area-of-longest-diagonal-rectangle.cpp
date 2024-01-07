class Solution {
public:
    typedef long long ll;
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       int n=dimensions.size();
       double maxD=0,maxA=0;
       for(int i=0;i<n;i++){
           // area of rectangle = l*b
           int l=dimensions[i][0];
           int b=dimensions[i][1];
           double Dlen=sqrt(l*l + b*b);
           double area=l*b;
           if(Dlen>maxD){
               maxD=Dlen; 
               maxA=area;
           }
           else if(Dlen==maxD){
               if(area>maxA) maxA=area;
           }
       }
       return maxA;
    }
};