////////Longest Palindromic Subsequence

//// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-palindromic-subsequence-1612327878


class Solution {
    public:
      int dp[1001][1001];
      int LCS(string &a, string &b,int i,int j){
          if(i==a.size()|| j==b.size()) return 0;
          if(dp[i][j] !=-1) return dp[i][j];
          if(a[i]==b[j]) return dp[i][j]=1+LCS(a,b,i+1,j+1);
           else return dp[i][j]=max(LCS(a,b,i,j+1),LCS(a,b,i+1,j));
      }
      int longestPalinSubseq(string &s) {
          memset(dp,-1,sizeof(dp));
          string rev=s;
          reverse(rev.begin(),rev.end());
          return LCS(s,rev,0,0);
      }
  };