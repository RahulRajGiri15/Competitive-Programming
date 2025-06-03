////////Substrings with K Distinct


////////https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

class Solution {
public:
    int countSubstr(string& s, int k) {
        int n      = s.length();
        int result = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);     // frequency array to store character counts
            int         distinctCnt = 0; // number of distinct characters in current window

            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a'] == 0) {
                    distinctCnt++;  // new distinct character found
                }
                freq[s[j] - 'a']++; // increment frequency of current character

                if (distinctCnt == k) {
                    result++; // valid substring with exactly k distinct characters
                } else if (distinctCnt > k) {
                    break;    // more than k distinct characters, break early
                }
            }
        }
        return result;
    }
};

