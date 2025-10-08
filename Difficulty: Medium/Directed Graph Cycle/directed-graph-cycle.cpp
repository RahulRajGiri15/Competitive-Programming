class Solution {
  public:
    bool dfss(vector<vector<int>>&adj,int u,vector<bool>&visited , vector<bool>&inrecursion){
        visited[u] = true;
        inrecursion[u] = true;
        
        for(auto &v : adj[u]){
            if(visited[v] == true && inrecursion[v] == true){
                return true;
            }
            else if(visited[v] == false && dfss(adj,v,visited,inrecursion)){
                return true;
            }
        }
        
        inrecursion[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        ////visited vector
        vector<bool>visited(V,false);
        vector<bool>inrecursion(V,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false && dfss(adj,i,visited,inrecursion)){
                return true;
            }
        }
        return false;
        
    }
};