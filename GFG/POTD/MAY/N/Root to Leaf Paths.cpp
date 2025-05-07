///////Root to Leaf Paths

/////https://www.geeksforgeeks.org/problem-of-the-day?itm_source=geeksforgeeks&itm_medium=main_header&itm_campaign=practice_header


class Solution {
    public:
      void getPaths(Node* root, vector<int>path, vector<vector<int>>& res) {
         if(root==NULL)return;
         path.push_back(root->data);
         if(root->left==NULL && root->right==NULL)res.push_back(path);
         getPaths(root->left,path,res);
         getPaths(root->right,path,res);
         path.pop_back();
     }
      vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>res;
        vector<int>path;
        if(root==NULL)return res;
        getPaths(root,path,res);
        return res;
      }
  };