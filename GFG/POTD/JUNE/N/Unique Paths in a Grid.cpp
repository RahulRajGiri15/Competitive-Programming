////////Unique Paths in a Grid

////https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1

class Solution {
  public: 
    int n,m;
    int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>>&dp){
        // base case
        if(i>=n || j>=m || grid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        //recursive case 
        return dp[i][j] = solve(grid,i+1,j,dp) + solve(grid,i,j+1,dp);
    }
    int uniquePaths(vector<vector<int>> &grid) {
        //CodeGenius
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,0,0,dp);
        
    }
};