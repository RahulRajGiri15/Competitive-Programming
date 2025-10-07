class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfss(vector<vector<int>>&adj,int u,vector<bool>&visited,vector<int>& res){
        queue<int>que;
        visited[u] = true;
        que.push(u);
         res.push_back(u);
        while(!que.empty()){
            int u = que.front();
           
            que.pop();
            for(auto &v : adj[u]){
                if(visited[v] == false){
                    que.push(v);
                    visited[v] = true;
                    res.push_back(v);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int v = adj.size();
        vector<bool>visited(v,false);
        vector<int> res;
        bfss(adj,0,visited,res);
        return res;
    }
};