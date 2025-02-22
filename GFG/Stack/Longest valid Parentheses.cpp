/////Longest valid Parentheses
//////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/longest-valid-parentheses5657


class Solution {
    public:
      int maxLength(string& s) {
          stack<int>st;
          int maxi = 0;
          st.push(-1); /////for cases like this -> ()
          for(int i=0; i<s.size(); i++){
              if(s[i]=='(' ) st.push(i);
              else{
                  st.pop();
                  if(!st.empty())  maxi = max(maxi, i - st.top());
                  else st.push(i);
              }
          }
          return maxi;
      }
  };