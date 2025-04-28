///////////Count Subarrays With Score Less Than K

/////////https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/?envType=daily-question&envId=2025-04-28

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();
            
    
            long long result = 0;
            long long sum    = 0;
    
            int i = 0;
            int j = 0;
    
            while(j < n) {
                sum += nums[j];
    
                while(i <= j && sum * (j - i + 1) >= k) { //shrink the window
                    sum -= nums[i];
                    i++;
                }
    
                //i...j
                //i+1...j
                //i+2...j
                result += (j-i+1);
                j++;
            }
    
            return result;
        }
    };
    
    
    
    ///////////////////// 
    // class Solution {
    // public:
    //     long long countSubarrays(vector<int>& nums, long long k) {
    //         int n = nums.size();
    //         long long cnt =0;
    //         for(int i=0;i<n;i++){
    //             int sum = 0;
    //             int len =0;
    //             for(int j=i;j<n;j++){
    //                 sum += nums[j];
    //                 len = j-i+1;
    //                 if((long long) sum * len < k){
    //                     cnt++;
    //                 }
                    ///////
    //                 if((long long) sum * j-i+1 < k){
    //                     cnt++;
    //                 }
    //             }
    //         }
    //         return cnt;
    //     }
    // };
    
    /////////////////////////
    // class Solution {
    // public:
    //     long long countSubarrays(vector<int>& nums, long long k) {
    //         long long sum=0;
    //         int n = nums.size();
    //         long long cnt =0;
    //         for(int i=0;i<n;i++){
    //             for(int j=i;j<n;j++){
    //                 vector<int>ans;
    //                 sum=0;
    //                 for(int k=i;k<=j;k++){
    //                     sum += nums[k];
    //                     ans.push_back(nums[k]);
    //                 }
    //                 if(sum * ans.size() < k){
    //                     cnt++;
    //                 }
    //                 ans.clear();
    //             }
    //         }
    //         return cnt;
    //     }
    // };