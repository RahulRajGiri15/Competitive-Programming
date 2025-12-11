class Solution {
  public:
    void insertstack(stack<int> &st, int x){
        ///if empty or top elemnt is less x
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
            
        }
        //otherwise
        int temp = st.top();
        st.pop();
        insertstack(st,x);
        st.push(temp);
        
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        
        sortStack(st);
        insertstack(st,x);
    }
};
