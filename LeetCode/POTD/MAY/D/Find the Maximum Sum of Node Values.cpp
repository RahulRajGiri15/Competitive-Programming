////////////Find the Maximum Sum of Node Values


///////////https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-question&envId=2025-05-23

//////////t-o(n)
////////s-o(n)

class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll normalsum =0;
        vector<int>fayda;
        for(int i=0;i<nums.size();i++){
            normalsum += nums[i];
            fayda.push_back((nums[i]^k) - nums[i]);
        }
        sort(begin(fayda),end(fayda),greater<int>());///decending
        int n = fayda.size();
        for(int i=0;i<n-1; i +=2){
            ll pairsum = fayda[i] + fayda[i+1];
            if(pairsum > 0){
                normalsum +=pairsum;
            }
        }
        return normalsum;
    }
};

////////////


// class Solution {
// public:
//     typedef long long ll;
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         ll sum =0;
//         int count = 0;
//         int MinNuksaan = INT_MAX;
//         for(ll num : nums){
//             if((num^k) > num){
//                 count++;
//                 sum += (num^k); 
//             }
//             else{
//                 sum += num;
//             }
//             MinNuksaan = min((long long)MinNuksaan , abs(num - (num^k)));
//         }
//         if(count %2 != 0){ ///// in case of odd XOR
//             // sum -= MinNuksaan;
//             return sum - MinNuksaan;
//         }
//         return sum;
//     }
// };    







////////////////////
// class Solution {
// public:
//     typedef long long ll;
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         ll sum=0;
//         int count=0;
//         int MinNuksaan = INT_MAX;
//         for(int i=0;i<nums.size();i++){
//             int xored = nums[i] ^ k;
//             if(xored > nums[i]){
//                 nums[i] = xored;
//                 count++;
//             }
//             else if(xored < nums[i]){
//                 MinNuksaan = min((long long) MinNuksaan , nums[i]-xored);
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             sum += nums[i];
//         }
//         if(count %2 != 0 && MinNuksaan != INT_MAX){
//             sum = sum - MinNuksaan;
//         }
//         // else if(count %2 == 0){
//         //     sum = sum;
//         // }
//         return sum;
//     }
// };