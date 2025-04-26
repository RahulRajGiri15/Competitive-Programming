////////Count Subarrays With Fixed Bounds

///https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n = nums.size();
            long long count = 0;
    
            for (int start = 0; start < n; ++start) {
                int currentMin = nums[start];
                int currentMax = nums[start];
    
                for (int end = start; end < n; ++end) {
                    currentMin = min(currentMin, nums[end]);
                    currentMax = max(currentMax, nums[end]);
    
                    if (currentMin == minK && currentMax == maxK) {
                        count++;
                    }
                }
            }
    
            return count;
        }
    };