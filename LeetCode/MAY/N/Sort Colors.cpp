//////Sort Colors

////////https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;   //denotes for 0
        int j = 0;   //denotes for 1
        int k = n-1; //denotes for 2
        
        while ( j <= k) {
            if(nums[j] == 1) {
                j++;
            } else if(nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else { //nums[j] == 0
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
    }
};

///////by two pointers
///logic

////////t-o(n^2)
////s-o(1)
// int n = nums.length();
// while(l<n){
//     r=l;
//     while(r<n){
//         if(nums[l]>nums[r]){
//             swap(nums[l],nums[r]);
//             r++;
//         }
//     }
//     l++;
// }

// //////////////by counting the nums///counting sort
///t-o(n)
///s-o(1)
// class Solution {
// public:
//     void sortColors(vector<int>& nums){
//         int cnt1=0,cnt2=0,cnt0=0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]==0)cnt0++;
//             if(nums[i]==1)cnt1++;
//             if(nums[i]==2)cnt2++;
//         }
//         nums.clear();
//             while(cnt0 != 0){
//                 nums.push_back(0);
//                 cnt0--;
//             }
//             while(cnt1 != 0){
//                 nums.push_back(1);
//                 cnt1--;
//             }
//             while(cnt2 != 0){
//                 nums.push_back(2);
//                 cnt2--;
//             }
        
//     }
// }; 

/////////////sorting algorithm
////t-o(n^2)
////s-o(1)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=1;j<n-i;j++){
//                 if(nums[j-1]>nums[j]){
//                     swap(nums[j],nums[j-1]);
//                 }
//             }
//         }                                       
//     }
// }; 

// //////////////unordered_map////wrong
// #include<unordered_map>
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         unordered_map<int,int>mp;
//         for(int i :nums){
//             mp[i]++;
//         }           
//         nums.clear();
//         for(auto &it:mp){
//             int cnt=0;
//             while(cnt< it.second){
//                 nums.push_back(it.first);
//                 cnt++;
//             }
//         }                                     
//     }
// }; 

