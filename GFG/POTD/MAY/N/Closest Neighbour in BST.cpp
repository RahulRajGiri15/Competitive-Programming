////////Closest Neighbour in BST

//////////https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // CodeGenius
        int ans=-1;
        Node *curr=root;
        while(curr){
            if(curr->data<=k){
                ans=curr->data;
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        return ans;
    }
};