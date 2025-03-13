////////////Maximum Count of Positive Integer and Negative Integer

///////https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12

class Solution {
    public:
        // int maximumCount(vector<int>& nums) {
        //     int countneg =0;
        //     int countpos =0;
        //     for(int i=0;i<nums.size();i++){
        //         if(nums[i]>0) countpos++;
        //         else if (nums[i]<0) countneg++;
        //     }        
        //     return max(countpos,countneg);
    
            /////////m2 using binary search approach--for O(log(n))
            int maximumCount(vector<int>& nums) { 
                int n = nums.size();
                int high = n-1;
                int negpos = binarysearch(nums,0,high,-1); ///negcount == negpos
                int pospos = binarysearch(nums,negpos,high,0);
                int poscount = (n - pospos);
                return max(negpos,poscount);
            }
            int binarysearch(vector<int>& nums , int low, int high, int target){
                while(low <= high){
                    int mid = low + (high-low) /2;
                    if(nums[mid] <= target) low = mid+1;
                    else high = mid-1; 
                }
                return low;
            }
            
    };