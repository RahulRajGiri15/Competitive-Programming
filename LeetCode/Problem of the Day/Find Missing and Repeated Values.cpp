/////Find Missing and Repeated Values

////https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            // unordered_set<int> set;
            // int n=grid.size();
            // int sq = n*n;
            // int currSum=0;
            // vector<int> ans(2);
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<n;j++){
            //         if(set.find(grid[i][j]) != set.end()){
            //             ans[0] = grid[i][j];
            //         }else{
            //             set.insert(grid[i][j]);
            //             currSum += grid[i][j];
            //         }
            //     }
            // }
            // int totalsum = sq* (sq+1)/2;
            // ans[1]=totalsum-currSum;
            // return ans;
    
            //method 2
            int n = grid.size();
            unordered_map<int,int> count;
             // Count occurrences of each number
            for(int i =0 ;i<n;i++){
                for(int j=0;j<n;j++){
                    count[grid[i][j]] += 1;
                }
            }
             // Check which number is missing and which is repeated
            int doublee = 0 , missing =0;
            for(int num =1 ; num< n*n+1;num++){
                if(count[num]==0) missing = num;
                else if(count[num]== 2) doublee =num;
            }
            return {doublee , missing};
        }
    };