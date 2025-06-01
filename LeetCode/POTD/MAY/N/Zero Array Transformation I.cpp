///////Zero Array Transformation I

/////////https://leetcode.com/problems/zero-array-transformation-i/?envType=daily-question&envId=2025-05-20


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        //Step-1 Make diff array using query
        vector<int> diff(n, 0);
        for(auto &query : queries) {
            int start = query[0];
            int end   = query[1];
            int x     = 1;

            diff[start] += x;
            if(end+1 < n) {
                diff[end+1] -= x;
            }
        }

        //Step-2. Find cumulative effect on each index
        vector<int> result(n, 0);
        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];
            result[i] = cumSum;
        }

        for(int i = 0; i < n; i++) {
            if(result[i] < nums[i]) { //nums[i] won't become 0 ever
                return false;
            }
        }

        return true;
    }
};

