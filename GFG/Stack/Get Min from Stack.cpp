////////////////Get Min from Stack

//////////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/get-minimum-element-from-stack

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mini ;
    stack<int> st;
    Solution() {
        // code here
    }
    //////Method 1 
    // Add an element to the top of Stack
    void push(int x) {
    if(st.empty())  mini = x;
    else if(x<=mini) {
        st.push(mini);  ///this will help while we pop one mini we need prev mini
        mini=x;
    }
    st.push(x);
    }
    // Remove the top element from the Stack
    void pop() {
        if(st.empty()) return;
        int temp =st.top();
        st.pop();
        if(temp==mini && !st.empty()){
            mini = st.top();
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};

/////////////Method 2 --- not correct now 
// class Solution {
//   public:
//     int mini ;
//     stack<int> st;
//     Solution() {
//         mini = INT_MAX;
//     }
//         void push(int x){
//             if(st.empty()){ 
//                 mini =x;
//                 st.push(x);
//             }
//             else{
//                 if(x>mini) st.push(x);
//                 else{
//                     st.push(2*x-mini);
//                     mini=x;
//                 }
//             }
//         }
//         void pop(){
//             if(st.empty()) return ;
//             int top = st.top();
//             st.pop();
//             if (top < mini){
//                 mini = 2*mini - top; ////restore prev min
//             }
//             if(st.empty()){
//                 mini = INT_MAX; ////ReSet mini when stack is empty
//             }
//         }
//         int peek(){
//             if(st.empty()) return -1;
//             int top = st.top();
//             return(mini<=top)? top:mini; 
            
//         }
//         int getMin(){
//             return(st.empty()) ? -1: mini;
            
//         }
// };

//////////method 3 -- Brute force
///// using stack<pair<int,int>> st --- write push,pop,peek,getMin

// class Solution {
//   public:
//     stack<pair<int,int>>st;
//     Solution() {
      
//     }
//     void push(int x){
//         if(st.empty())
//             st.push({x,x});
//         else
//             st.push({x,min(x,st.top().second)});
//     }
//     void pop(){
//         if(!st.empty())
//             st.pop();
//     }
//     int peek(){
//         if(st.empty()) return -1;
//         return st.top().first;
//     }
//     int getMin(){
//         if(st.empty()) return -1;
//         return st.top().second;
//     }
// };  
        

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends