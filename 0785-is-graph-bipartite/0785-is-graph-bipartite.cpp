class Solution {
public:
    bool DFS(vector<vector<int>>& graph,int curr,vector<int>&color,int currColor){
        color[curr]=currColor; // curr node ko color kardiya
        
        // aab jate haii adjecent node par
        for(int &v: graph[curr]){
            if(color[v]==color[curr]){
                return false;
            }
            if(color[v]==-1){ // never colored means never visited
                int colorOfv=1-currColor; // 1-0=1, 1-1=0
                if(DFS(graph,v,color,colorOfv)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int> color(n,-1); // no node colored in the start
      /*
         red--> 1
         green --> 0 
       */
       for(int i=0;i<n;i++){
           if(color[i]==-1){
               if(DFS(graph,i,color,1)==false){
                   return false;
               }
           }
       }
       return true;
    }
};