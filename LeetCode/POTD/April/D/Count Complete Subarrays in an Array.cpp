//////////Count Complete Subarrays in an Array

///////https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24

/////optimized -=-- sliding window///
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_set<int>st(nums.begin(),nums.end());
            int cnt = st.size();
            int left=0;
            int right=0;
            int result=0;
            int n = nums.size();
            unordered_map<int,int>mp;
            while(right<n){
                mp[nums[right]]++;
                while(mp.size()==cnt){
                    result += n-right;
                    
                    mp[nums[left]]--;
                    if(mp[nums[left]] == 0){
                        mp.erase(nums[left]);
                    }
                    left++;
                }
                right++;
            }
            return result;
        }
    };
    
    
    //////////// Sliding Window////
    // class Solution {
    // public:
    //     int countCompleteSubarrays(vector<int>& nums) {
    //         unordered_map<int,int>mp;
    //         int n = nums.size();
    //         for(int ni : nums){
    //             mp[ni]++;
    //         }
    //         int ucnt = mp.size();
    //         int cnt=0;
    //         int left =0,right=0;
    //         while(left<n){
    //             right =left;
    //             unordered_map<int,int>mp;
    //             while(right<n){
    //                 mp[nums[right]]++;
    //                 if(mp.size() == ucnt){
    //                     cnt += n-right;
    //                     break;
    //                 }
    //                 right++;
    //             }
    //             mp.clear();
    //             left++;
    //         }
    //         return cnt;
    //     }
    // };
    
    /////////////Hashing /// Iteration//////
    // class Solution {
    // public:
    //     int countCompleteSubarrays(vector<int>& nums) {
    //         unordered_map<int,int>mp;
    //         int n = nums.size();
    //         for(int ni : nums){
    //             mp[ni]++;
    //         }
    //         int ucnt = mp.size();
    //         int cnt=0;
    //         for(int i=0;i<n;i++){
    //             for(int j=i;j<n;j++){
    //                 unordered_map<int ,int>ansmp;
    //                 for(int k=i;k<=j;k++){
    //                     ansmp[nums[k]]++;
    //                 }
    //                 if(ansmp.size() == ucnt) cnt++; 
    //                 ansmp.clear();
    //             }
    //         }
    //         return cnt;
    //     }
    // };