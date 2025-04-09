///Minimum Operations to Make Array Values Equal to K

///////https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int mini = nums[0];
            if (mini < k) return -1;
    
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > k) {
                    cnt++;
                    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                        i++;  // skip duplicates
                }
            }
            return cnt;
        }
    };
    