////Parenthesis Checker
////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/parenthesis-checker2744

class Solution {
    public:
      bool isBalanced(string& s) {
          stack<char>st;
          for(int i= 0 ; i<s.size(); i++){
              if(s[i] == '(' || s[i]=='[' || s[i]=='{' ) st.push(s[i]);
              else{
                  if(!st.empty() && ((s[i]==')' && st.top()=='(' ) || 
                  ( s[i]==']' && st.top()=='[' )||(s[i]=='}' && st.top()=='{'))) st.pop();
                  else return false;
              }
          }
          return st.empty();
      }
  };