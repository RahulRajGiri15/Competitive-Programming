/////Print leaf nodes from preorder traversal of BST

////////https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

///////
class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        //CodeGenius
        stack<int>st;
        vector<int>ans;
        
        st.push(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            if(preorder[i]<st.top()) st.push(preorder[i]);
            else{
                int temp=st.top();
                int count=0;
                while(!st.empty() && preorder[i]>st.top()){
                    st.pop();
                    count++;
                }
                st.push(preorder[i]);
                if(count>=2) ans.push_back(temp);
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};