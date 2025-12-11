class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return ;
        }
        
        int x = st.top();
        st.pop();
        reverseStack(st); ///trust
        
        stack<int>tempst;
        while(!st.empty()){
            tempst.push(st.top());
            st.pop();
        }
        st.push(x);///insert the fist ele 
        while(!tempst.empty()){
            st.push(tempst.top());
            tempst.pop();
        }

        
    }
};