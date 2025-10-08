class Solution {
  public:
  
    bool dfss(vector<vector<int>>&adj,int u,vector<bool>&visited,int parent){
        visited[u] = true;
        for(auto &v : adj[u]){
            if(v == parent) continue;
            if(visited[v] == true)return true;
            if(dfss(adj,v,visited,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
            for(auto &it : edges){
                int u = it[0];
                int v = it[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            
        vector<bool>visited(V,false);
        bool iscy = false;
        for(int i=0;i<V;i++){
            if(visited[i] == false && dfss(adj,i,visited,-1)){
                iscy = true;
                break;
            }
        }
        if(iscy == true){
            return true;
        }
        return false;
    }
};