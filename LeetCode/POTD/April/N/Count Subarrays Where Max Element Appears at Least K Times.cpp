//////Count Subarrays Where Max Element Appears at Least K Times

////https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2025-04-29




class Solution {
    #define ll long long
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll valid_subarrays = 0;
        int win_count = 0;
        int left = 0,right = 0;

        int maximum = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        while(left<n){
            while(right<n and win_count<k){
                if(nums[right]==maximum)
                    win_count++;
                right++;
            }

            if(win_count==k)
                valid_subarrays += n-right+1;
            
            if(nums[left]==maximum)
                win_count--;
            left++;
        }
        return valid_subarrays;
    }
};