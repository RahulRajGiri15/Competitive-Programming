///////Distribute Candies Among Children II


////////https://leetcode.com/problems/distribute-candies-among-children-ii/?envType=daily-question&envId=2025-06-01

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int minch1 = max(0, n - 2 * limit);
        int maxch1 = min(n, limit);

        for(int i = minch1;i<= maxch1;i++){  ///here ch1 is fixed
            int N = n - i;

            int minch2 = max(0, N - limit);
            int maxch2 = min(N, limit);
            
            ways += maxch2 - minch2 + 1;
        }
        return ways;
    }
};

//////a