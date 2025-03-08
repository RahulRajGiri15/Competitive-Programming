//////////Longest Palindrome in a String


///////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-palindrome-in-a-string3411

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n=s.size();
        if(n==0) return "";
        int  start =0, maxLen=1;
        auto expandAroundCenter =[&](int left,int right){
            while(left>=0 && right <n && s[left] == s[right]){
                int len = right -left +1;
                if(len > maxLen){
                    maxLen = len;
                    start = left;
                    
                }
                left --;
                right++;
            }
        };
        for(int i=0;i<n;i++){
            expandAroundCenter(i,i);
            expandAroundCenter(i,i+1);
        }
        return s.substr(start,maxLen);
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends