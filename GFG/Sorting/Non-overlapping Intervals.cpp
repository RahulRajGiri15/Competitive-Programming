//Non-overlapping Intervals

///Main algorithm code 

class Solution {
    public:
      int minRemoval(vector<vector<int>> &intervals) {
          int deletecount = 0;
          sort(intervals.begin(),intervals.end());
          int prev = intervals[0][1];
          for(int i=1;i<intervals.size();i++){
              if(intervals[i][0] < prev){
                  deletecount++;
                  prev=min(prev,intervals[i][1]);
              }
              else{
                  prev=intervals[i][1];
              }
      }
      return deletecount;
      }
  };

  