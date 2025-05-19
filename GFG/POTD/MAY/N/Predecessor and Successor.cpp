//////Predecessor and Successor


///////////https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution {
public:

    // Helper function to perform inorder traversal and store nodes in a vector
    void inorder(Node* root, vector<Node*>& result) {
        if (!root) {
            return;
        }
        inorder(root->left, result);         // Traverse left subtree
        result.push_back(root);              // Visit current node
        inorder(root->right, result);        // Traverse right subtree
    }
    // Function to find predecessor and successor of given key
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> result;                // Vector to store inorder traversal result

        inorder(root, result);               // Fill the vector with inorder traversal

        Node* pre = NULL;                    // Pointer to store predecessor
        Node* suc = NULL;                    // Pointer to store successor

        for (int i = 0; i < result.size(); i++) {
            if (result[i]->data < key) {
                pre = result[i];             // Keep updating predecessor until key is found
            } else if (result[i]->data > key) {
                suc = result[i];             // First greater element after key is the successor
                break;
            } else {
                if (i - 1 >= 0) {
                    pre = result[i - 1];     // Element before key is predecessor
                }
                if (i + 1 < result.size()) {
                    suc = result[i + 1];     // Element after key is successor
                }
                break;                       // Break after finding key
            }
        }
        return { pre, suc };                   // Return both predecessor and successor
    }
};