///////////Merge Two 2D Arrays by Summing Values

///////////https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int i =0 , j=0;
            vector<vector<int>> ans;
            while(i< nums1.size() && j < nums2.size()){
                if(nums1[i][0] < nums2[j][0]){
                    ans.push_back(nums1[i]);
                    i += 1;
                }
                else if(nums1[i][0] > nums2[j][0]){
                    ans.push_back(nums2[j]);
                    j +=1;
                }
                else{
                    ans.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
                    i = i+1;
                    j = j+1;
                }
            }
            while(i < nums1.size()){
                ans.push_back(nums1[i]);
                i++;
            }
            while(j < nums2.size()){
                ans.push_back(nums2[j]);
                j++;
            }
            return ans;
        }
    };