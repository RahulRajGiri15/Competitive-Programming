////////Find Subarrays With Equal Sum

////https://leetcode.com/problems/find-subarrays-with-equal-sum/

class Solution {
    public:
        bool findSubarrays(vector<int>& nums) {
            ////A subarray is a contiguous non-empty sequence of elements within an array.
            int n = nums.size();
            unordered_set<int> sumss;
            for(int i =0;i<n-1;i++){
                int sum = nums[i]+nums[i+1];
                ////// Check if we've already seen this sum
                if(sumss.find(sum) != sumss.end()){
                    return true;
                }
                else{
                    sumss.insert(sum);
                }
            }
            return false;
    
        }
    };
            // if(idx == num.size()){
            //     if(sos == tare)
            // }
            // findsubarrays(num,idx+1,sub+arr[idx]+",",sos+arr[i])
            // findsubarrays(nums,idx+1,sub,sos,)
            
            // int n = nums.size();
            // for(int i =0;i<n;i++){
            //     for(int j =i+1;j<n;j++){
            //         sos += nums[i][j];
            //     }
                
            // }
    ////////////////////
    