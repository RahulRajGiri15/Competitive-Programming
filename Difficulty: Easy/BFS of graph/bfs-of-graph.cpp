// ////////BFS 

// class Solution {
//   public:
//     // Function to return Breadth First Traversal of given graph.
//     void BFS(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited,vector<int>& result){
//         /////////for BFS  take a queue
//         if(visited[u] == true) return ;
//         visited[u] = true;
//         queue<int>que;
//         que.push(u);
//         result.push_back(u);
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//             for(auto &v : adj[u]){
//                 if(visited[v] == false){
//                     que.push(v);
//                     visited[v] = true;
//                     result.push_back(v);
//                 }
//             }
//         }
//     }
//     vector<int> bfs(vector<vector<int>> &mp) {
//         unordered_map<int ,vector<int>>adj;
//         int V = mp.size();
//         for(int u=0;u<V;u++){
//             for(int v : mp[u]){
//                 adj[u].push_back(v);
//             }
//         }
//         vector<int>result;
//         vector<bool>visited(V,false);
//         BFS(adj,0,visited,result);
//         return result;
//     }
// };

/////////////////////////////////BFS-- in this we use queue 


class Solution {
  public:
    void BFSS(unordered_map<int,vector<int>>& adj,int u,vector<int>& result,vector<int> & visited){
        queue<int>qu;
        qu.push(u);
        visited[u] = true;
        result.push_back(u);
        while(!qu.empty()){
            u = qu.front();
            qu.pop();
            for(auto &v : adj[u]){
                if(!visited[v]){
                    qu.push(v);
                    result.push_back(v);
                    visited[v] = true;
                }
            }
        }
    }
    vector<int> bfs(vector<vector<int>> &mp) {
        int V = mp.size();
        unordered_map<int,vector<int>>adj;
        
        for(int u=0;u<V;u++){
            for(int &v : mp[u]){
                adj[u].push_back(v);
            }
        }
        vector<int>visited(V,false);
        vector<int>result;
        BFSS(adj,0,result,visited);
        return result;
        
    }
};