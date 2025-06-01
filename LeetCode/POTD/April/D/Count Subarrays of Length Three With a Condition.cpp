////////Count Subarrays of Length Three With a Condition

///https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27

/////Best
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int cnt=0;
            for(int i=0;i<=nums.size()-3;i++){
                if(nums[i+1]%2 ==0 && nums[i]+nums[i+2] == nums[i+1]/2){
                    cnt++;
                }
            }
            return cnt;
        }
    };
    /////Best-2
    // class Solution {
    // public:
    //     int countSubarrays(vector<int>& nums) {
    //         int cnt=0;
    //         int left =0 ;
    //         int right=nums.size()-3;
    //         while(left<=right){
    //             if(nums[left+1]%2 ==0 && nums[left]+nums[left+2] == nums[left+1]/2){
    //                 cnt++;
    //             }
    //             left++;
    //         }
    //         return cnt;
    //     }
    // };
    
    /////less worst approach 
    
    // class Solution {
    // public:
    //     int countSubarrays(vector<int>& nums) {
    //         int n = nums.size();
    //         int cnt=0;
    //         for(int i =0;i<n;i++){
    //             for(int j=0;j<n;j++){
    //                 if(j-i+1 == 3){
    //                     if(nums[i+1]%2 == 0 && nums[i]+nums[i+2] == nums[i+1]/2){
    //                         cnt++;
    //                     }
    //                 }
    //             }
    //         }
    //         return cnt;
    //     }
    // };
    
    ////////////////////////worst approach--TLE
    
    // class Solution {
    // public:
    //     int countSubarrays(vector<int>& nums) {
    //         int n = nums.size();
    //         int cnt=0;
    //         for(int i=0;i<n;i++){
    //             for(int j=i;j<n;j++){
    //                 vector<int>arr;
    //                 for(int k=i;k<=j;k++){
    //                     arr.push_back(nums[k]);
    //                 }
    //                 if(arr.size() == 3){
    //                     if(arr[1] % 2==0 && arr[0]+arr[2] == arr[1]/2){
    //                         cnt++;
    //                     }
    //                 }
    //                 arr.clear();
    //             }
    //         }
    //         return cnt;
    //     }
    // };