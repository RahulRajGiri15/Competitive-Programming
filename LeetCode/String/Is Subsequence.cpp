/////Is Subsequence

////https://leetcode.com/problems/is-subsequence/description/

// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         //////approach
//         ///find all the subsequence and sotre it in a array than search weather element exist     or not
//     vector<string>ans = allsubseq(t);
//     // if(ans.find(t) != end()){
//         for(string str: ans){
//             if(str == s) return true;
//         }
//         return false;
//     }
//     vector<string> allsubseq(string str){
//         if(str.size()==0){
//             vector<string> bres;
//             bres.push_back("");
//             return bres;
//         }
//         char ch = str[0];
//         string ros = str.substr(1);
//         vector<string> res = allsubseq(ros);
//         vector<string> mres;
//         for(string str:res){
//             mres.push_back(""+str);
//             mres.push_back(ch +str);
//         }
//         return mres;
//     }
// };
///////////////////////optimized method///////

// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//       int n1 = t.size();
//       int n2 = s.size();
//       int k=0;
//       for(int i =0;i<n1;i++){
//         if(s[k]== t[i]) {
//             k++;
//         }
//       }
//       if(k == n2) return true;
//       else return false;
//     }
// };

////////////optimal 2

class Solution {
    public:
        bool isSubsequence(string s, string t) {
    
            int i=0,j=0;
            while(i<s.size() && j<t.size()){
                if(s[i]== t[j]){ 
                    i++;
                }
                j++;
            }
            if(i == s.size()) return true;
            else return false;
        }
    };
    