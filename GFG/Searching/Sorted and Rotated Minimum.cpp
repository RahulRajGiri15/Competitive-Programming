//////Sorted and Rotated Minimum
//// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/minimum-element-in-a-sorted-and-rotated-array3611


class Solution {
    public:
      int findMin(vector<int>& arr) {
          // method 1 -- Brute force
          // int minval = INT_MAX;
          // for(int i=0;i<arr.size();i++){
          //     minval=min(arr[i],minval);
          // }
          // return minval;
          
          /////method 2 -- Optimal
          int low = 0, high = arr.size()-1 , ans = INT_MAX;
          while(low <= high){
              int mid = (low + high) / 2;
              // if array is already sorted than //// 1-2-3
              if(arr[low] <= arr[high]){
                  ans = min(ans, arr[low]);
              }
              if(arr[low] <= arr[mid]){
                  ans = min(ans , arr[low]);
                  low = mid+1;
              }
              else{
                  high = mid-1;
                  ans = min(ans, arr[mid]);
              }
              
          }
          return ans;
      }
  };