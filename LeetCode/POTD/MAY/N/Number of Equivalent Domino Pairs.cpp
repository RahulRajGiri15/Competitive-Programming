/////Number of Equivalent Domino Pairs

//////https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<pair<int, int>, int> mp;
    
            for(auto &d : dominoes) {
                if(d[0] > d[1]) { //(2, 1) ---- (1, 2)
                    swap(d[0], d[1]);
                }
    
                mp[{d[0], d[1]}]++;
            }
    
            int result = 0;
    
            for(auto &it : mp) {
                int freq = it.second;
    
                result += freq * (freq-1)/2; //freqC2
            }
    
            return result;
    
        }
    };