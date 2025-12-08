class myStack {
  public:
    stack<int> st;
    int ns;
    
    myStack(int n) {
        // Define Data Structures
        ns = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return (st.empty() == true);
    }

    bool isFull() {
        // check if the stack is full
        return (st.size() == ns);
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(st.size() != ns){
            st.push(x);
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(st.empty() != true){
            st.pop();
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }
};