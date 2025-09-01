
////////////

// class Solution {
//   public:
//     void DFS(vector<vector<int>>& adj,int u,vector<int>&result,vector<bool>& visited){
//         if(visited[u] == true) return ;
//         visited[u] =  true;
        
//         result.push_back(u);
//         for(int &v : adj[u]){
//             if(!visited[v]){
//                 DFS(adj,v,result,visited);
//             }
//         }
//     }
//     vector<int> dfs(vector<vector<int>>& adj) {
//         int V = adj.size();
//         /////making our adjency list 
//         // unordered_map<int,vector<int>> adj;
//         // for(int u=0;u<V;u++){ /// for row 
//         //     for(int v=0; v<V; v++){ ///for column
//         //         if(mp[u][v] == 1){
//         //             adj[u].push_back(v);
//         //         }
//         //     }
//         // }
//         vector<int>result;
//         vector<bool>visited(V,false);
//         DFS(adj,0,result,visited);
//         return result;
//     }
// };

//////////////

// class Solution {
//   public:
//     void DFS(unordered_map<int,vector<int>>& adj,int u,vector<int>&result,vector<bool>& visited){
//         if(visited[u] == true) return ;
//         visited[u] =  true;
        
//         result.push_back(u);
//         for(int &v : adj[u]){
//             if(!visited[v]){
//                 DFS(adj,v,result,visited);
//             }
//         }
//     }
//     vector<int> dfs(vector<vector<int>>& mp) {
//         int V = mp.size();
//         ///making our adjency list 
//         unordered_map<int,vector<int>> adj;
//         for(int u=0;u<V;u++){ /// for row 
//             for(int v : mp[u]){
//                 adj[u].push_back(v);
//             }
//         }
//         vector<int>result;
//         vector<bool>visited(V,false);
//         DFS(adj,0,result,visited);
//         return result;
//     }
// };

///////////////



class Solution {
  public:
    void DFSS(unordered_map<int,vector<int>>&adj,int u,vector<int>& result,vector<bool>& visited){
        if(visited[u] == true) return ;
        
        visited[u] = true;
        result.push_back(u);
        for(int &v : adj[u]){
            if(visited[v] == false)
                DFSS(adj,v,result,visited);
            }
        }
        
    
    vector<int>dfs(vector<vector<int>>& mp) {
        int V = mp.size();
        /////making our adjency list
        unordered_map<int,vector<int>> adj;
        for(int u=0;u<V;u++){ //// for row
            for(int v : mp[u]){
                adj[u].push_back(v);
            }
        }
        vector<int>result;
        vector<bool>visited(V,false);
        DFSS(adj,0,result,visited);
        return result;
    }
};































////////////////////////

// class Solution {
//   public:
//     void DFS(unordered_map<int,vector<int>>& adj,int u,vector<int>&result,vector<bool>& visited){
//         if(visited[u] == true) return ;
//         visited[u] =  true;
        
//         result.push_back(u);
//         for(int &v : adj[u]){
//             if(!visited[v]){
//                 DFS(adj,v,result,visited);
//             }
//         }
//     }
//     vector<int> dfs(vector<vector<int>>& mp) {
//         int V = mp.size();
//         /////making our adjency list 
//         unordered_map<int,vector<int>> adj;
//         for(int u=0;u<V;u++){ /// for row 
//             for(int v=0; v<V; v++){ ///for column
//                 if(mp[u][v] == 1){
//                     adj[u].push_back(v);
//                 }
//             }
//         }
//         /////sorting adjency (vector)
//         for(auto &entry : adj){
//             sort(entry.second.begin(),entry.second.end());
//         }
        
//         vector<int>result;
//         vector<bool>visited(V,false);
//         /////running dfs for all the component
//         for(int i=0;i<V;i++){
//             if(!visited[i]){
//               DFS(adj,i,result,visited);  
//             }
//         }
        
//         return result;
//     }
// };