////////Checking if Graph is cyclic//////////

//////////Using DFS

// class Solution {
//   public:
//     bool iscycleDFS(vector<vector<int>>& adj,int u,vector<bool>& visited,int parent){
//         visited[u] = true;
//         for(auto &v : adj[u]){
//             if(v == parent) continue;
//             if(visited[v]){
//                 return true; //// there is cycle present
//             }
//             if(iscycleDFS(adj,v,visited,u)){
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         // convert all the edges to the adjaency list 
//         vector<vector<int>>adj(V);
//         for(auto &e : edges){
//             int u = e[0],v=e[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u); /// because it's a undirected graph
//         }
        
//         vector<bool>visited(V,false);
//         for(int i=0;i<V;i++){
//             if(visited[i] == false && iscycleDFS(adj,i,visited,-1)){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

/////////////Using BFS

// class Solution {
//   public:
//     bool iscycleBFS(vector<vector<int>>& adj,int u,vector<bool>& visited,int parent){
//       queue<pair<int,int>>que;
//       que.push({u,-1});
//         visited[u] = true;
//         while(!que.empty()){
//             pair<int,int> p = que.front();
//             que.pop();
//             int source = p.first;
//             int parent = p.second;
            
//             for(int &v : adj[source]){
//                 if(visited[v] == false){
//                     visited[v] = true;
//                     que.push({v,source});
//                 }
//                 else if(v != parent){
//                     return true;
//                 }
//             }
//         }
//             return false;
//     }
        
//     bool isCycle(int V, vector<vector<int>>& edges) {
//         // convert all the edges to the adjaency list 
        
//         vector<vector<int>>adj(V);
//         for(auto &e : edges){
//             int u = e[0],v=e[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u); /// because it's a undirected graph
//         }
        
//         vector<bool>visited(V,false);
//         for(int i=0;i<V;i++){
//             if(visited[i] == false && iscycleBFS(adj,i,visited,-1)){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//////////////////////////////


class Solution {
  public:
    bool iscycleDFS(vector<vector<int>>& adj,int u,vector<bool>& visited,int parent){
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(v == parent) continue;
            if(visited[v] == true) return true; /// cycle is present
            if(iscycleDFS(adj,v,visited,u) == true){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // it is undirected graph
        // convert all the edges to the adjaency list 

        vector<vector<int>>adj(V);
        for(auto &e : edges){
            int u = e[0], v= e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false && iscycleDFS(adj,i,visited,-1)){
                return true;
            }
        }
        return false;
    }
};
