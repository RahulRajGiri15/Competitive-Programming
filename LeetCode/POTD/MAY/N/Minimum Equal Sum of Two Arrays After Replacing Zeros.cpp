////Minimum Equal Sum of Two Arrays After Replacing Zeros

////////https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        long long zero1 = 0;
        long long zero2 = 0;

        for(int &num : nums1) {
            sum1 += num;
            if(num == 0) { //to get minimum sum, add smallest positive i.e. 1
                zero1 += 1;
                sum1 += 1;
            }
        }

        for(int &num : nums2) {
            sum2 += num;
            if(num == 0) { //to get minimum sum, add smallest positive i.e. 1
                zero2 += 1;
                sum2 += 1;
            }
        }

        if((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) {
          return -1;
        }
        
        return max(sum1, sum2);
    }
};