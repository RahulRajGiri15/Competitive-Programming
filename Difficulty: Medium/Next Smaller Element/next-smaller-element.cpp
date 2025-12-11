// class Solution {
//   public:
//     vector<int> nextSmallerEle(vector<int>& arr) {
//         //  code here
//         int n = arr.size();
//         vector<int>ans(n,-1);
        
//         for(int i=0;i<n;i++){
//             int mi = arr[i];
//             for(int j=i+1;j<n;j++){
//                 if(arr[i] > arr[j]){
//                     ans[i] = arr[j];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/////////////////

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1:st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};