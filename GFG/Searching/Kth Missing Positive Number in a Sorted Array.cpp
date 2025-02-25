//////////////Kth Missing Positive Number in a Sorted Array

////////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/kth-missing-positive-number-in-a-sorted-array

// User function template for C++

class Solution {
    public:
      int kthMissing(vector<int> &arr, int k) {
          ///Brute force
          // for(int i =0; i<arr.size(); i++){
          //     if(arr[i] <= k) k++;
          //     else break;
          // }
          // return k;
          
          //////Binary Search
          int n = arr.size();
          int low =0, high= n-1;
          while(low<=high){
              int mid=(low+high)/2;
              int missing = arr[mid] - (mid+1);
              if(missing < k) low = mid+1;
              else high = mid-1;
          }
          //return (high +1 + k);
          //or 
          return (low + k);
      }
  };
  