///////Count the Number of Ideal Arrays

//////https://leetcode.com/problems/count-the-number-of-ideal-arrays/description/?envType=daily-question&envId=2025-04-22

class Solution {
    public:
        int M = 1e9+7;
        void findSets(int m, vector<int>& count, vector<vector<int>>& dp) {
            if(dp[m][1] != 0) {
                return;
            }
    
            dp[m][1] = 1;
            count[1]++;
    
            for(int div = 2; div <= m; div++) {
                if(m % div == 0) {
                    findSets(m/div, count, dp);
    
                    for(int len = 1; len < 15; len++) {
                        if(dp[m/div][len] != 0) {
                            dp[m][len+1] += dp[m/div][len];
                            count[len+1] += dp[m/div][len];
                        }
                    }
                }
            }
        }
    
        int findPower(long long a, long long b) {
            if(b == 0)
                return 1;
            
            long long half = findPower(a, b/2);
            long long result = (half * half) % M;
    
            if(b%2 == 1) {
                result = (result * a) % M;
            }
    
            return result;
        }
    
        int modularnCr(int n, int r, vector<long long>& fact) {
            if(r < 0 || r > n)
                return 0;
            
            long long b = (fact[r] * fact[n-r]) % M;
            return (fact[n] * findPower(b, M-2)) % M;
        }
    
        int idealArrays(int n, int maxVal) {
            vector<vector<int>> dp(maxVal+1, vector<int>(15, 0));
            vector<int> count(15, 0);
    
            //Find sets count
            for(int val = 1; val <= maxVal; val++) {
                findSets(val, count, dp);
            }
    
            //Precompute factorials
            vector<long long> fact(n+1, 1);
            for(int i = 2; i <= n; i++) {
                fact[i] = (fact[i-1] * i) % M;
            }
    
            long long result = 0;
            for(int len = 1; len < 15; len++) {
                if(n < len) {
                    break;
                }
                if(count[len] != 0) {
                    long long possibilities = modularnCr(n-1, len-1, fact);
                    result = (result + (count[len] * possibilities)%M) % M;
                }
            }
    
            return (int)result;
    
        }
    };
    
    
    
    //////recursion////////
    // class Solution{
    //     public:
    //     int m = 1e9+7;
    //     int solve(int start,int count,int n,int maxVal){
    //         if(count == n) return 1;
    //         long long result =0;
    //         for(int mul=1; start*mul<=maxVal;mul++){
    //             result = (result + solve(start*mul,count+1,n,maxVal))%m;
    //         }
    //         return result;
    //     }
    //     int idealArrays(int n , int maxValue){
    //         long long result=0;
    //         for(int startVal =1;startVal<=maxValue;startVal++){
    //             result = (result + solve(startVal,1,n,maxValue)) % m;
    //         }
    //         return result;
    //     }
    // };
    
    ///////////////////
    // #include<vector>
    // class Solution {
    // public:
    //     int idealArrays(int n, int maxValue) {
    //       vector<int>arr;
    //       for(int i=1;i<=maxValue;i++){ 
    //         arr.push_back(i);
    //       }
    //       int cnt=0;
    //       for(int i=0;i<arr.size();i++){
    //         for(int j=0;j<n;j++){
    //             if(arr[i] % arr[i-1]==0){
    //                 cnt++;
    //             }
    //         }
    //       }
    //       return cnt;                           
    //     }
    // };