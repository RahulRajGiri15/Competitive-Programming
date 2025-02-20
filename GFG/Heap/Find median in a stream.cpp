///////Find median in a stream
//// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/find-median-in-a-stream-1587115620

class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          priority_queue<int> leftmaxHeap;
          priority_queue<int , vector<int>, greater<int>>rightminHeap;
          vector<double> ans; 
          for(int i=0; i<arr.size();i++){
              leftmaxHeap.push(arr[i]);
              int ele = leftmaxHeap.top();
              rightminHeap.push(ele);
              leftmaxHeap.pop();
              
              if(rightminHeap.size() > leftmaxHeap.size()){
                  int ele = rightminHeap.top();
                  leftmaxHeap.push(ele);
                  rightminHeap.pop();
              }
              
              double median;
              if(leftmaxHeap.size() != rightminHeap.size()){
                  median = leftmaxHeap.top();
              }
              else{
                  median = double(leftmaxHeap.top() + rightminHeap.top()) / 2;
              }
              ans.push_back(median);
          }
          return ans;
      }
  };