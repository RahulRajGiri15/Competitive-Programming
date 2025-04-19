//////////Count the Number of Fair Pairs

//https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19

class Solution{
    public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());///o(nlogn)
        long long result=0;
        for(int i=0;i<n;i++){///o(n)
            ///gives first element less than lower-nums[i] /// o(logn)
            int idx = lower_bound(begin(nums)+i+1, end(nums),lower-nums[i])-begin(nums);
            ///no of all the pairs whoese sum is    <=lower-nums[i]
            int x = idx-i-1;
            ///gives first element greater than upper-nums[i]////o(log n)
            int udx = upper_bound(begin(nums)+i+1, end(nums),upper-nums[i])-begin(nums);
            ///no of all the pairs whoese sum is <=upper-nums[i]
            int y = udx-1-i;
            
            result += (y-x);
        }
        return result;
    }
};

////t-o(n*log n)
///s-o(1)

//////////////////////brute force approcach//////
// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         long long  cnt=0;
//         long long  n = nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]+nums[j]>=lower && nums[i]+nums[j]<=upper){
//                     cnt++;
//                 }
//             }
//         }
//     return cnt;
//     }
// };