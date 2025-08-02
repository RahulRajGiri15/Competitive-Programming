// User function Template for C++

class Solution {
  public:
    void DFS(unordered_map<int, vector<int>>& adj,int u,vector<bool>& visited,vector<int>& result){
        visited[u] = true;
        result.push_back(u);
        for(auto &v : adj[u]){
            if(visited[v] == false){
                DFS(adj,v,visited,result);
            }
        }
    }
    int numProvinces(vector<vector<int>> adjj, int V) {
        
        unordered_map<int, vector<int>>adj;
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(adjj[u][v] == 1){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        ///now write code for dfs
        vector<bool>visited(V,false);
        vector<int> result;
        int cnt = 0 ; 
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                DFS(adj,i,visited,result);
                cnt++;
            }
        }
        return cnt;
    }
};
