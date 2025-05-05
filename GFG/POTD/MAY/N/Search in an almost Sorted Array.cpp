////Search in an almost Sorted Array

////https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          for(int i=0;i<arr.size();i++){
              if(arr[i] == target){
                  return i;
              }
          }
          return -1;
      }
  };
  