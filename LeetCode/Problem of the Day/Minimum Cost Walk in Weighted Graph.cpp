////Minimum Cost Walk in Weighted Graph

//https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/?envType=daily-question&envId=2025-03-20

class Solution {
    #define pii pair<int,int>

    int find(vector<int>& dsuf,int v){
        if(dsuf[v]==-1)
            return v;
        return dsuf[v] = find(dsuf,dsuf[v]);
    }
    void traverseComponent(int& bitwise_and,int curr,vector<bool>& visited,vector<vector<pii>>& adj){
        visited[curr] = true;
        for(auto& [nbr,wt]: adj[curr]){
            bitwise_and &= wt;
            if(!visited[nbr])
                traverseComponent(bitwise_and,nbr,visited,adj);
        }
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        //Step-1: Keep components segregated using disjoint set and make Adj-List
        vector<int> dsuf(n,-1);
        vector<vector<pii>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(make_pair(edge[1],edge[2]));
            adj[edge[1]].push_back(make_pair(edge[0],edge[2]));

            int px = find(dsuf,edge[0]);
            int py = find(dsuf,edge[1]);
            if(px != py)
                dsuf[px] = py;
        }

        //Step-2: Precompute minimum walk cost for each component
        unordered_map<int,int> parent_cost;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                int bitwise_and = adj[i].size()==0? 0: adj[i][0].second;
                traverseComponent(bitwise_and,i,visited,adj);
                int parent = find(dsuf,i);
                parent_cost[parent] = bitwise_and;
            }
        }
        //Step-3: Calculate each query
        vector<int> ans;
        for(auto& q: query){
            int px = find(dsuf,q[0]);
            int py = find(dsuf,q[1]);
            if(px==py)  ans.push_back(parent_cost[px]);
            else        ans.push_back(-1);
        }
        return ans;
    }
};