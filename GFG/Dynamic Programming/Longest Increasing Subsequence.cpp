/////////////Longest Increasing Subsequence

///https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-increasing-subsequence-1587115620


class Solution {
    public:
      int lis(vector<int>& arr) {
          ////M1-Dynamic programming Approach 
          
          
          
          /// M2- Binary search appraoch
          vector<int>ans;
          ans.push_back(arr[0]);
          for(int i=0;i<arr.size();i++){
              if(arr[i]>ans.back()) ans.push_back(arr[i]);
              else{
                  
                  int idx = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin(); 
                  //replaces the first element >= arr[i]
                  ans[idx]=arr[i];
              }
          }
          return ans.size();
          
      }
  };
  