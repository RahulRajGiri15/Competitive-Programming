class Solution {
  public:
    bool iscycle(vector<vector<int>>& adj,int u,vector<bool>& visited,int parent){
        visited[u] = true;
        for(auto &v : adj[u]){
            if(v == parent) continue;
            if(visited[v]){
                return true; //// there is cycle present
            }
            if(iscycle(adj,v,visited,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // convert all the edges to the adjaency list 
        vector<vector<int>>adj(V);
        for(auto &e : edges){
            int u = e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); /// because it's a undirected graph
        }
        
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false && iscycle(adj,i,visited,-1)){
                return true;
            }
        }
        return false;
    }
};