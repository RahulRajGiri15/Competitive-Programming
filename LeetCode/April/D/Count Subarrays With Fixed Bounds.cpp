////////Count Subarrays With Fixed Bounds

///https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26

////Sliding window
////T-o(n)
///s-o(1)
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n = nums.size();
            long long res =0;
            int minpos=-1;
            int maxpos =-1;
            int culprtidx =-1;
            int temp=0,small =0;;
            for(int i=0;i<n;i++){
               if(nums[i] == minK){
                 minpos = i;
               }
               if(nums[i] == maxK){
                 maxpos = i;
               }
               if(nums[i] > maxK || nums[i] < minK){
                 culprtidx = i;
               }
               long long small = min(minpos , maxpos);
               long long temp = small - culprtidx;
               res+=(temp <0 )?0 :temp;
            }
            return res;
        }
     };
           
    ///////////////////Brute force
    ////T-o(n^2)
    ////S--o(1)
    // class Solution {
    // public:
    //     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    //         long long cnt=0;
    //         int n =nums.size();
            
    //         for(int start =0;start<n;start++){
    //             int mini = nums[start];
    //             int maxi = nums[start];
    //             for(int end=start;end<n;end++){
    //                 mini = min(mini,nums[end]);
    //                 maxi = max(maxi,nums[end]);
    //                 if(maxi == maxK && mini == minK){
    //                     cnt++;
    //                 }
    //             }
    
    //         }
    //         return cnt;
    //     }
    // };
    
    //////////////////worst-TLE
    ////T-o(n^3)
    ////s-o(n)
    // class Solution {
    // public:
    //     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    //         long long cnt=0;
    //         int n =nums.size();
    //         for(int i=0;i<n;i++){
    //             for(int j=i;j<n;j++){
    //                 vector<int>ans;
    //                 int maxi =INT_MIN;
    //                 int mini =INT_MAX;
    //                 for(int k=i;k<=j;k++){
    //                     maxi = max(maxi,nums[k]);
    //                     mini = min(mini,nums[k]);
    //                     ans.push_back(nums[k]);
    //                 }
    //                 if(mini == minK && maxi == maxK){
    //                     cnt++;
    //                 }
    //                 ans.clear();
    //                 mini=0;
    //                 maxi=0;
    //             }
    //         }
    //         return cnt;
    //     }
    // };
    
    