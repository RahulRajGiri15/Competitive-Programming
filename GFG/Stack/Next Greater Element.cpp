//////////Next Greater Element
//////////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/next-larger-element-1587115620


class Solution {
    public:
      // Function to find the next greater element for each element of the array.
      vector<int> nextLargerElement(vector<int>& arr) {
          int n = arr.size();
          stack<int> st;
          vector<int>ans(n,-1);
          for(int i=n-1; i >=0;i--){
              while(!st.empty() && st.top() <= arr[i]) st.pop();
              if(!st.empty()) ans[i] = st.top();
              st.push(arr[i]);
              
          }
          return ans;
      }
  };