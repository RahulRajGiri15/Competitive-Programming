//////Maximize the Number of Target Nodes After Connecting Trees II


/////////https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/?envType=daily-question&envId=2025-05-29

///////

class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    //O(V+E)
    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent, vector<int>& mark, 
        int &zeroMarkedCount, int& oneMarkedCount) {

        if(mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }

        for(auto &ngbr : adj[curr]) {
            if(ngbr != parent) {
                mark[ngbr] = (mark[curr] == 0) ? 1 : 0; //alternate marking
                dfs(ngbr, adj, curr, mark, zeroMarkedCount, oneMarkedCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size()+1; // Tree A
        int M = edges2.size()+1; // Tree B

        unordered_map<int, vector<int>> adjA = getAdj(edges1); //O(V1+E1)
        unordered_map<int, vector<int>> adjB = getAdj(edges2); //O(V2+E2)

        vector<int> markA(N, -1);
        markA[0] = 0; //mark 0th node as 0
        int zeroMarkedCountA = 0;
        int oneMarkedCountA  = 0;
        dfs(0, adjA, -1, markA, zeroMarkedCountA, oneMarkedCountA); //O(V+E)


        vector<int> markB(M, -1);
        markB[0] = 0; //mark 0th node as 0
        int zeroMarkedCountB = 0;
        int oneMarkedCountB  = 0;
        dfs(0, adjB, -1, markB, zeroMarkedCountB, oneMarkedCountB); //O(V+E)

        int maxFromTree2 = max(zeroMarkedCountB, oneMarkedCountB);

        vector<int> result(N);
        for(int i = 0; i < N; i++) { //O(V)
            result[i] = (markA[i] == 0 ? zeroMarkedCountA : oneMarkedCountA) + maxFromTree2;
        }

        return result;

        
    }
};
