////////Sum of nodes on the longest path


///////////https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:

    int maxLen = 0;  // Stores the length of the longest path from root to leaf
    int maxSum = 0;  // Stores the maximum sum along the longest path

    void dfs(Node* node, int currLen, int currSum) {
        if (!node) {
            return;  // Base case: if node is null, just return
        }

        currLen += 1;             // Increment path length
        currSum += node->data;    // Add node value to path sum

        // If it's a leaf node
        if (!node->left && !node->right) {
            // If this path is longer than the previous longest
            if (currLen > maxLen) {
                maxLen = currLen;
                maxSum = currSum;
            }
            // If path length is same but sum is greater
            else if (currLen == maxLen && currSum > maxSum) {
                maxSum = currSum;
            }
            return;
        }

        // Recur for left and right subtree
        dfs(node->left, currLen, currSum);
        dfs(node->right, currLen, currSum);
    }
    
    int sumOfLongRootToLeafPath(Node* root) {
        dfs(root, 0, 0);  // Start DFS with initial length and sum as 0
        return maxSum;    // Return the max sum found
    }
};
