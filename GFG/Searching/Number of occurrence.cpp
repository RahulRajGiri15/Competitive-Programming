////Number of occurrence
///https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/number-of-occurrence2259

/////optimal solution 
//// time complexity ->  o(log n)
//// binary search approach
class Solution {
    public:
      int firstocc(vector<int>& arr, int& target){
          int s = 0 , e = arr.size() -1 ;
          int ans = -1;
          while(s<=e){
              int mid = (s+e)/2;
              if(arr[mid ]== target){
                  ans = mid;
                  e = mid-1;
              }
              else if (arr[mid] > target) e = mid -1 ;
              else s = mid+1;
          }
          return ans;
      }
      int lastocc(vector<int>& arr, int& target){
          int s = 0 , e = arr.size() -1 ;
          int ans = -1;
          while(s<=e){
              int mid = (s+e)/2;
              if(arr[mid ]== target){
                  ans = mid;
                  s = mid+1;
              }
              else if (arr[mid] > target) e = mid -1 ;
              else s = mid+1;
          }
          return ans;
      }
      int countFreq(vector<int>& arr, int target) {
          // optimal approach -- using binary search -- O(log n)
          if(lastocc(arr,target) == -1 && firstocc(arr,target) == -1) return 0;
          return lastocc(arr,target) - firstocc(arr,target) + 1 ;
      }
  };



  ///////brute force approach

  class Solution {
    public:

    int countFreq(vector<int>& arr, int target) {
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == target) count++;
        }
        return count;
    }
}