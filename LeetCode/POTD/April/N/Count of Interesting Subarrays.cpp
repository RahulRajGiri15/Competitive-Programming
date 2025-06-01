//////Count of Interesting Subarrays

//////https://leetcode.com/problems/count-of-interesting-subarrays/description/?envType=daily-question&envId=2025-04-25

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
            ///m - modulo
            int n = nums.size();
            // for(int i=0;i<n;i++){
            //     if(nums[i] % m == k){
            //         nums[i] =1;
            //     }
            //     else{
            //         nums[i] = 0;
            //     }
            // }
            unordered_map<int,long long> mp;
            long long sum=0;
            long long result =0;
            mp[0] = 1;
            for(int i=0;i<n;i++){
                /////m-2
                if(nums[i] % m == k){
                    sum += 1;
                }
                /////
                //sum += nums[i];
                int r1=sum%m;
                int r2 = (r1-k+m)%m;
                result += mp[r2];
                mp[r1]++;
            }
            return result;
        }
    };