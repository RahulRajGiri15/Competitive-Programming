/////////Longest Common Subsequence


///////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-common-subsequence-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1001][1001];
    int LCS(int i ,int j, string &s1, string &s2) {
        // code here
        if(i==s1.size() || j==s2.size()) return 0;
        //recursive case
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+LCS(i+1,j+1,s1,s2);
        else return dp[i][j]=max(LCS(i,j+1,s1,s2),LCS(i+1,j,s1,s2));
    }
    int lcs(string &s1 , string &s2){
        //Code Genius
        memset(dp,-1,sizeof(dp));
        return LCS(0,0,s1,s2);
    }A
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends