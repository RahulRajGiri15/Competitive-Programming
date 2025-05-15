/////////Longest Unequal Adjacent Groups Subsequence I

/////////https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

////t-o(n)
///s-o(n)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    
        vector<string>st;
        for(int i=0;i<words.size();i++){
            
            if(i == 0 || groups[i] != groups[i-1]){
                st.push_back(words[i]);
            }
            
        }
        return st;
    }
};
///////////////////////////

////t-o(n)
///s-o(n)
// class Solution {
// public:
//     vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
//         /////if string length is 1
//         if(words.size()==1) return words;
//         //////more than 1
//         vector<string>st;
//         st.push_back(words[0]);
//         int j=0;
//         for(int i=1;i<words.size();i++){
            
//             if(groups[i] == groups[i-1]){
//                 continue;
//             }
//             else{
//                 st.push_back(words[i]);
//             }
            
//         }
//         return st;
//     }
// };

////////////////////////
////t-o(n)
///s-o(n)
// class Solution {
// public:
//     vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
//         /////if string length is 1
//         if(words.size()==1) return words;
//         //////more than 1
//         vector<string>st;
//         st.push_back(words[0]);
//         int j=0;
//         for(int i=1;i<words.size();i++){
//             if(groups[i] != groups[j]){
//                 st.push_back(words[i]);
//                 j=i;
//             }
//         }
//         return st;
//     }
// };