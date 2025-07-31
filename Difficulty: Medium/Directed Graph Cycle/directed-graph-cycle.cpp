class Solution {
  public:
    bool iscycleDFS(vector<vector<int>>& adj, int u ,vector<bool>& visited ,vector<bool>& inrecursion){
        visited[u] = true;
        inrecursion[u] = true;
        
        for(auto &v : adj[u]){
            ////if not visited than we check for cycle in DFS
            if(visited[v] == false && iscycleDFS(adj,v,visited,inrecursion)){
                return true;
            }
            else if(inrecursion[v] == true){
                return true;
            }
        }
        inrecursion[u] = false;
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            
        }
        
        vector<bool>visited(V,false);
        vector<bool>inrecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(visited[i] == false && iscycleDFS(adj,i,visited,inrecursion)){
                return true;
            }
        }
        return false;
    }
};