/////Type of Triangle

/////////https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19

class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool valid = (nums[0] + nums[1] > nums[2]) &&
                     (nums[0] + nums[2] > nums[1]) &&
                     (nums[1] + nums[2] > nums[0]);

        if(!valid) {
            return "none";
        }

        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if(nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) {
            return "scalene";
        }

        return "isosceles";
    }
};
