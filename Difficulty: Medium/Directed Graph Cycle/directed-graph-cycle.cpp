/////////using DFS 

// class Solution {
//   public:
//     bool iscycleDFS(vector<vector<int>>& adj, int u ,vector<bool>& visited ,vector<bool>& inrecursion){
//         visited[u] = true;
//         inrecursion[u] = true;
        
//         for(auto &v : adj[u]){
//             ////if not visited than we check for cycle in DFS
            
//             // if(visited[v] == false && iscycleDFS(adj,v,visited,inrecursion)){
//             //     return true;
//             // }
//             ///////or
//             if(visited[v] == false ) {
//                 if(iscycleDFS(adj,v,visited,inrecursion)){
//                     return true;
//                 }
//             }
//             else if(inrecursion[v] == true){
//                 return true;
//             }
//         }
//         inrecursion[u] = false;
//         return false;
        
//     }
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         // code here
//         vector<vector<int>> adj(V);
//         for(auto &e : edges){
//             int u = e[0], v = e[1];
//             adj[u].push_back(v);
            
//         }
        
//         vector<bool>visited(V,false);
//         vector<bool>inrecursion(V,false);
        
//         for(int i=0;i<V;i++){
//             if(visited[i] == false && iscycleDFS(adj,i,visited,inrecursion)){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

////t-o(V+E)
////s-o(V+E)

/////////////Using BFS

////in this we write khans algorithm to find topological sort 
///as topological sort only works in directed acylic graph 
///so if we can find topogical sort -- than there is no cycle other wise there is cycle

// class Solution {
//   public:
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         // code here
//         vector<vector<int>> adj(V);
//         for(auto &e : edges){
//             int u = e[0], v = e[1];
//             adj[u].push_back(v);
//         }
        
//         /////1 make indegree vector
//         vector<int>indegree(V,0);
//         for(int u=0;u<V;u++){
//             for(auto &v : adj[u]){
//                 indegree[v]++;
//             }
//         }
//         ////2 fill vertex whose indree = 0 in  queue
//         queue<int>que;
//         for(int u=0;u<V;u++){
//             if(indegree[u] == 0){
//                 que.push(u);
//             }
//         }
//         ///now travese in queue and perform the operations
//         int cnt=0;
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//             cnt++;
//             for(auto &v : adj[u]){
//                 indegree[v]--;
                
//                 if(indegree[v] == 0){
//                     que.push(v);
//                 }
//             }
//         }
//         if(cnt == V) return false; /// as we can find topological sort 
        
//         return true; ///we can't find topological sort
//     }
// };

////t--o(V+E)
////s--o(V+E)



//////////another way -- using khan's algorimthm -- using BFS

// class Solution {
//   public:
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         // code here
//         vector<vector<int>> adj(V);
//         for(auto &e : edges){
//             int u = e[0], v = e[1];
//             adj[u].push_back(v);
//         }
        
//         /////1 make indegree vector
//         vector<int>indegree(V,0);
//         for(int u=0;u<V;u++){
//             for(auto &v : adj[u]){
//                 indegree[v]++;
//             }
//         }
//         ////2 fill vertex whose indree = 0 in  queue
//         int cnt=0;
//         queue<int>que;
//         for(int u=0;u<V;u++){
//             if(indegree[u] == 0){
//                 que.push(u);
//                 cnt++;
//             }
//         }
//         ///now travese in queue and perform the operations
//         while(!que.empty()){
//             int u = que.front();
//             que.pop();
//             for(auto &v : adj[u]){
//                 indegree[v]--;
                
//                 if(indegree[v] == 0){
//                     que.push(v);
//                     cnt++;
//                 }
//             }
//         }
//         if(cnt == V) return false; /// as we can find topological sort 
        
//         return true; ///we can't find topological sort
//     }
// };

////t--o(V+E)
////s--o(V+E)


/////////////////////////////////////////////


class Solution {
  public:
    bool iscyclicDFS(vector<vector<int>>& adj, int u,vector<bool>& visited,vector<bool>& inrecursion){
        visited[u] = true;
        inrecursion[u] = true;
        
        for(auto &v : adj[u]){
            if(visited[v] == false && iscyclicDFS(adj,v,visited,inrecursion)){
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
            int u = e[0],v = e[1];
            adj[u].push_back(v);
        }
        vector<bool>visited(V,false);
        vector<bool>inrecursion(V,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false && iscyclicDFS(adj,i,visited,inrecursion)){
                return true;
            }
        }
        return false;
    }
};

























