//////////Coin Change (Minimum Coins)

/////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/number-of-coins1824

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum+1,INT_MAX);
        dp[0] = 0;
        for(int coin: coins){
            for(int i = coin; i<=sum;i++){
                if(dp[i-coin] != INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coin]);
                }
            }
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends