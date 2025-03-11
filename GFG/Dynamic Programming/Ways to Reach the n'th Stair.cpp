////////////Ways to Reach the n'th Stair

/////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-ways-to-reach-the-nth-stair-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // int solve(int n){
    //     if(n<=2) return n; /////base case
        
    //     return solve(n-1)+solve(n-2);
    // }
    // int countWays(int n) {
    //     return solve(n);
    // }
    //////
    // int dp[45];
    // int solve(int n){
    //     if(n<=2) return n; /////base case
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n]= solve(n-1)+solve(n-2);
    // }
    // int countWays(int n) {
    //     memset(dp,-1,sizeof(dp));
    //     return solve(n);
    // }
    ///////////
    // int dp[45];
    // int solve(int n){
    //      dp[0]=0;
    //      dp[1]=1;
    //      dp[2]=2;
    //     for(int i=3;i<n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }
    // int countWays(int n) {
        
    //     return solve(n);
    // }
    //////

    int solve(int n){
        int prev1 = 1;
        int prev2 = 1;
        int curr;
        for(int i=2;i<=n;i++){
             curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
    int countWays(int n) {
        
        return solve(n);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends