class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    void Union(int u,int v){
        u=find(u);
        v=find(v);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]<rank[u]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string &s: equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }  
        }
        for(string &s: equations){
            if(s[1]=='!'){
                char first=s[0]-'a';
                char second=s[3]-'a';
                int find_first=find(first);
                int find_second=find(second);
                
                if(find_first==find_second){
                    return false;
                }
            }
        }
        return true;
    }
};