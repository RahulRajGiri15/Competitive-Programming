class Solution {
  public:
    void topoDFS(vector<vector<int>>& adj,int u,vector<bool>& visited,stack<int>&stres){
        visited[u] = true;
        
        for(auto & v : adj[u]){
            if(visited[v] == false){
                topoDFS(adj,v,visited,stres);
            }
        }
        stres.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto ed : edges){
            int u=ed[0],v = ed[1];
            adj[u].push_back(v);
        }
        stack<int>stres;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                topoDFS(adj,i,visited,stres);
            }
        }
        vector<int>result;
        while(!stres.empty()){
            result.push_back(stres.top());
            stres.pop();
        }
        return result;
    }
};