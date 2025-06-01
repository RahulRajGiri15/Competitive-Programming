///////Longest Palindrome by Concatenating Two Letter Words

///////https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/?envType=daily-question&envId=2025-05-25

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        int result = 0;

        for(string &word : words) {
            string reversedWord = word;
            swap(reversedWord[0], reversedWord[1]);

            if(mp[reversedWord] > 0) {
                result += 4;
                mp[reversedWord]--;
            } else {
                mp[word]++;
            }
        }

        //Check equal character words. Use only one
        for(auto &it : mp) {
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0) {
                result += 2;
                break;
            }
        }

        return result;
    }
};

