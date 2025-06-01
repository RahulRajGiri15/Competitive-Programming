//////Find Closest Node to Given Two Nodes

///////https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-question&envId=2025-05-30

class Solution {
public:
    int n;
    
    void bfs(vector<int>& edges, int startNode, vector<int>& dist_node) {
        queue<int> que;
        que.push(startNode);
        dist_node[startNode] = 0;
        vector<bool> visited(n, false);
        visited[startNode] = true;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                visited[v] = true;
                dist_node[v] = 1 + dist_node[u];
                que.push(v);
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);
        
        
        int minDistNode    = -1;
        int minDistTillNow = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            int maxD = max(dist1[i], dist2[i]);
            
            if (minDistTillNow > maxD) {
                minDistNode = i;
                minDistTillNow = maxD;
            }
        }

        return minDistNode;
        
    }
};
