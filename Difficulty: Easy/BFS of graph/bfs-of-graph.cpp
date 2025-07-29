class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void BFS(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited,vector<int>& result){
        /////////for BFS  take a queue
        if(visited[u] == true) return ;
        visited[u] = true;
        queue<int>que;
        que.push(u);
        result.push_back(u);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto &v : adj[u]){
                if(visited[v] == false){
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &mp) {
        unordered_map<int ,vector<int>>adj;
        int V = mp.size();
        for(int u=0;u<V;u++){
            for(int v : mp[u]){
                adj[u].push_back(v);
            }
        }
        vector<int>result;
        vector<bool>visited(V,false);
        BFS(adj,0,visited,result);
        return result;
    }
};