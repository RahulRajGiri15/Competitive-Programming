class Solution {
  public:
    void dfss(vector<vector<int>>& adj, int u,vector<bool>&visited,vector<int>&res ){
        if(visited[u] == true){
            return;
        } 
        visited[u] = true;
        res.push_back(u);
        for(auto &v : adj[u]){
            if(visited[v] == false){
                dfss(adj,v,visited,res);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<bool>visited(v,false);
        vector<int>res;
        
        for(int u=0;u<v;u++){
            if(visited[u] == false){
                dfss(adj,u,visited,res);
            }
        }
        
       // dfss(adj,0,visited,res);
        
        return res;
    }
};