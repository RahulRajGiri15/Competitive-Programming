////////////////Decode the string

//////////https://www.geeksforgeeks.org/problems/decode-the-string2444/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i] != ']') st.push(s[i]);
            else{
                string word;
                while(!st.empty() && st.top() !='['){
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(),word.end());
                st.pop(); /// remove [
                string k;
                while(!st.empty() && isdigit(st.top())){
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(),k.end());
                int num = stoi(k);
                string repeat;
                for(int j=0; j<num; j++){
                    repeat.append(word);
                }
                for(char c : repeat) st.push(c);
            
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends