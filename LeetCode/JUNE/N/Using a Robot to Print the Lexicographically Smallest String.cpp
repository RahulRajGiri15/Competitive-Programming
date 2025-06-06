////////Using a Robot to Print the Lexicographically Smallest String

/////https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-question&envId=2025-06-06

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minCharToRight(n); //you can store index of those characters instead of storing characters

        minCharToRight[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--) {
            minCharToRight[i] = min(s[i], minCharToRight[i+1]);
        }


        string t = "";
        string paper = "";

        int i = 0; 
        while(i < n) {
            t.push_back(s[i]);

            char minChar = (i+1 < n) ? minCharToRight[i+1] : s[i];

            while(!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        //fill the remaining characters
        while(!t.empty()) {
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};
