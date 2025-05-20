/////////Burning Tree


/////https://www.geeksforgeeks.org/problems/burning-tree/1

class Solution {
public:
    int minTime(Node* root, int target) {
        // Step 1: Map each node to its parent and locate the target node
        queue<Node*> que;

        que.push(root);

        unordered_map<Node*, Node*> parent; // To store parent of each node
        parent[root] = nullptr;

        Node* tar = nullptr; // Pointer to store target node

        while (!que.empty()) {
            Node* curr = que.front();
            que.pop();

            // Locate the target node
            if (curr->data == target) {
                tar = curr;
            }

            // Map left child to parent
            if (curr->left) {
                que.push(curr->left);
                parent[curr->left] = curr;
            }

            // Map right child to parent
            if (curr->right) {
                que.push(curr->right);
                parent[curr->right] = curr;
            }
        }

        // Step 2: Simulate burning using BFS from target node
        unordered_map<Node*, bool> visited; // Track visited nodes to prevent re-burning
        int t = -1;                         // Time counter
        que.push(tar);                      // Start BFS from target node

        while (!que.empty()) {
            int n = que.size(); // Nodes burning at current second

            while (n--) {
                Node* curr = que.front();
                que.pop();

                visited[curr] = true; // Mark current node as burned

                // Spread to left child
                if (curr->left && !visited[curr->left]) {
                    que.push(curr->left);
                }

                // Spread to right child
                if (curr->right && !visited[curr->right]) {
                    que.push(curr->right);
                }

                // Spread to parent
                if (parent[curr] && !visited[parent[curr]]) {
                    que.push(parent[curr]);
                }
            }
            t++; // Increment time after processing current level
        }
        return t;
    }
};

