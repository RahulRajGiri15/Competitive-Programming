////////Count Subarrays of Length Three With a Condition

///https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
            int result = 0;
    
            for(int i = 1; i < n-1; i++) {
                if(nums[i] == (nums[i-1] + nums[i+1])*2) {
                    result++;
                }
            }
    
            return result;
        }
    
    };

    
