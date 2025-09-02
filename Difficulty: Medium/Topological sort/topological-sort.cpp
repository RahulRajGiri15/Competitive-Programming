//////////topological sort --- DFS

////do dfs and at end store the vertex
/// first store all the children v than store the parent u 
//// because when we get the element from the stack than u comes out first than v
///Because in topological sort u comes fist than v comes 

// class Solution {
//   public:
//     void topoDFS(vector<vector<int>>& adj,int u,vector<bool>& visited,stack<int>&stres){
//         visited[u] = true;
//         ////pahle mere ('u' node ke ) baccho ko dalo 
//         for(auto & v : adj[u]){
//             if(visited[v] == false){
//                 topoDFS(adj,v,visited,stres);
//             }
//         }
//         ////phir mujhe dalo stack me
//         stres.push(u);
//     }
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         // code here
//         vector<vector<int>>adj(V);
//         for(auto ed : edges){
//             int u=ed[0],v = ed[1];
//             adj[u].push_back(v);
//         }
//         stack<int>stres;
//         vector<bool>visited(V,false);
//         for(int i=0;i<V;i++){
//             if(visited[i] == false){
//                 topoDFS(adj,i,visited,stres);
//             }
//         }
//         vector<int>result;
//         while(!stres.empty()){
//             result.push_back(stres.top());
//             stres.pop();
//         }
//         return result;
//     }
// };

/////t--o(V+E)
////s--o(V+E)


//////////topological sort --- BFS ---KHAN's Algorithm

////In this we do sorting using BFS approach

// class Solution {
//   public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         ////1 -- make adjecent list 
//         vector<vector<int>>adj(V);
//         for(auto &ed : edges){
//             int u = ed[0],v=ed[1];
//             adj[u].push_back(v);
//         }
//         vector<int>indegree(V,0);
        
//         /////2 -- make indgree
//         for(int u=0;u<V;u++){
//             for(auto &v : adj[u]){
//                 indegree[v]++;
//             }
//         }
        
//         ////fill the indgree =0 in queue
//         queue<int>que;
//         for(int u=0;u<V;u++){
//             if(indegree[u] == 0){
//                 que.push(u);
//             }
//         }
//         vector<int>result;
//         while(!que.empty()){
//             int u = que.front();
//             result.push_back(u);
//             que.pop();
//             for(auto &v : adj[u]){
//                 indegree[v]--;
//                 if(indegree[v] == 0){
//                     que.push(v);
//                 }
//             }
//         }
//         return result;
//     }
// };

////t--o(V+E)
////s--o(V+E)


class Solution {
  public:
    void iscyclicBFS(vector<vector<int>>& adj,int u,vector<bool>& visited,stack<int>& st){
        visited[u] = true;
        for(auto &v : adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                iscyclicBFS(adj,v,visited,st);
                
            }
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u= e[0],v=e[1];
            adj[u].push_back(v); /// it is a directed graph
        }
        vector<bool>visited(V,false);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                iscyclicBFS(adj,i,visited,st);
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

