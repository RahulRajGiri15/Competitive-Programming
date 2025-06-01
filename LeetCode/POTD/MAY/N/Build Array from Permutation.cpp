///////Build Array from Permutation

///https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            vector<int>ans(n);
            for(int i=0;i<n;i++){
                ans[i] = nums[nums[i]];
            }
            return ans;
        }
    };