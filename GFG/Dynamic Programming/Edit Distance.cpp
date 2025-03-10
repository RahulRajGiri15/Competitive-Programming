/////////Edit Distance


////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/edit-distance3702

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int dp[1001][1001];
    int solve (string &s1,string &s2 ,int i,int j){
        if(i==s1.length()) return s2.length()-j;
        if(j==s2.length()) return s1.length()-i;
        if(dp[i][j] !=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,i+1,j+1);
        else{
            int insert = 1+solve(s1,s2,i,j+1);
            int dele =1+solve(s1,s2,i+1,j);
            int replace= 1+solve(s1,s2,i+1,j+1);
            return dp[i][j]= min({insert,dele,replace});
        }
    }
    int editDistance(string& s1, string& s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends