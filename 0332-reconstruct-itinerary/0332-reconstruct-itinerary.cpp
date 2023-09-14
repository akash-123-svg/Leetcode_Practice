class Solution {
public:
    unordered_map<string,vector<string>> adj;
    int numTickets=0;
    vector<string> result;
    bool DFS(string fromAirport,vector<string>&path){
        path.push_back(fromAirport);
        
        if(path.size()==numTickets+1){
            result=path;
            return true;
        }
        vector<string>&neighour=adj[fromAirport];
        for(int i=0;i<neighour.size();i++){
            string toAirport=neighour[i];
            neighour.erase(neighour.begin()+i);
            if(DFS(toAirport,path)){
                return true;
            }
            neighour.insert(neighour.begin()+i,toAirport);
        }
        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets=tickets.size();
        
        for(auto &t: tickets){
            string u=t[0];
            string v=t[1];
            adj[u].push_back(v);
        }
        for(auto &edges: adj){
          sort(begin(edges.second),end(edges.second));
        }
        vector<string> path;
        DFS("JFK",path);
        return path;
    }
};