//////////////Divisible and Non-divisible Sums Difference

//////////////////////https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/?envType=daily-question&envId=2025-05-27

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;

        return n*(n+1)/2 - m * k * (k+1);
    }
};
