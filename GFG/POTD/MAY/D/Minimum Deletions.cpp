/////////Minimum Deletions

//////////https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1

class Solution {
  public:
    //////pass s by refenence so that no new copies have to be made
    int solve(string &s ,string &r,int i ,int j,vector<vector<int>>&dp){
        if(i == s.size() || j == r.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j]; 
       int take = 0 , nottake =0;
       if(s[i] == r[j]){
            take = 1 + solve(s, r, i+1,j+1,dp);   
       }
          nottake = max(solve(s,r,i+1,j,dp) , solve(s,r,i,j+1,dp));
       return dp[i][j] = max(take ,nottake);
    }
    int minDeletions(string s) {
        // code here
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string r = s;
        reverse(r.begin(),r.end());
        return n - solve(s,r,0,0,dp);
    }
};