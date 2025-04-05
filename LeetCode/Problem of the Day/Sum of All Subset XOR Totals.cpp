///////Sum of All Subset XOR Totals
// Problem: https://leetcode.com/problems/sum-of-all-subset-xor-totals/


class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n = nums.size();
            int orr = 0;
            for(int ele: nums)
                orr |= ele;
            return orr * (1<<(n-1));
        }
    };