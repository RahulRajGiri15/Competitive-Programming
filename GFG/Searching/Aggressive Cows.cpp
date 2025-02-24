//////////////Aggressive Cows

////////////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows


class Solution {
    public:
    
      bool canweplace(vector<int> &stalls, int dist ,int cows){
          int cntcows =1 , last = stalls[0];
          for(int i = 1; i<stalls.size(); i++){
              if(stalls[i] - last >= dist){
                  cntcows++;
                  last = stalls[i];
              }
              if(cntcows >= cows) return true;
          }
          return false;
      }
  
      int aggressiveCows(vector<int> &stalls, int k) {
  
          sort(stalls.begin(),stalls.end());
          int n = stalls.size();
          int low =1 , high = stalls[n-1] -stalls[0];
          while(low <= high){
              int mid = (low+high) / 2;
              if(canweplace(stalls,mid,k) == true) {
                  low =mid+1;
              }
              else  high =mid-1;
      }
      return high;
      }
  };