//////Find First and Last Position of Element in Sorted Array

////////https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
    public:
        // vector<int> searchRange(vector<int>& nums, int target) {
        //     vector<int>ans;
        //     int i;
        //     int n =nums.size();
        //     if(n==1 && nums[0]==target){
        //         ans.push_back(0);
        //         ans.push_back(0);
        //         return ans;
        //     }
        //     //int s,
        //     for( i=0;i<nums.size();i++){
        //         if(nums[i]==target) ans.push_back(i);
        //     }
        //     if(ans.size() ==1) ans.push_back(ans[0]);
        //     if(ans.size()==0 && i==nums.size()){
        //         ans.push_back(-1);
        //         ans.push_back(-1);
        //         return ans;
        //     }
        //     else return ans;
        // }
        //////////////////
        vector<int> searchRange(vector<int>& nums, int target) {
            int n = nums.size();
            int left =0;
            int right =n-1;
            vector<int> ans;
            while(left<n){
                if(nums[left]==target){
                    ans.push_back(left);
                    break;
                }
                left++;
            }
            while(right>=0){
                if(nums[right]==target){
                    ans.push_back(right);
                    break;
                }
                right--; 
            }
    
            if(ans.size()==0 && left>right){
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            else return ans;
        }
    
    
    };