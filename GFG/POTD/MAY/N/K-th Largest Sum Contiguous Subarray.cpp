///////K-th Largest Sum Contiguous Subarray


/////https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        //CodeGenius
        int n=arr.size();
        vector<int>pre(n+1,0);
        
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+arr[i];
        priority_queue<int,vector<int>,greater<int>>mH;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int sum= pre[j]-pre[i];
                if(mH.size()<k) mH.push(sum);
                else if(sum>mH.top()){
                    mH.pop();
                    mH.push(sum);
                }
             }
        }
        return mH.top();
    }
};