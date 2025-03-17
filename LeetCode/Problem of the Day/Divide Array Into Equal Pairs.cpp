//////////Divide Array Into Equal Pairs

////////https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17

class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_set<int> remaining;
            for(int ele: nums){
                if(remaining.count(ele))    remaining.erase(ele);
                else                        remaining.insert(ele);
            }
            return remaining.size()==0;
        }
    };