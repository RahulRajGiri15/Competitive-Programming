////////Total Characters in String After Transformations I

////https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

/////////more optimized
/////////t-o(n+t)
/////////s-o(26)
class Solution {
public:
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        //unordered_map<char,int>mp;
        int n = s.size();
        vector<int>mp(26,0); 
        for(int i=0;i<n;i++){ ///o(n)
            mp[s[i]-'a']++;
        }
        for(int cnt=0; cnt<t;cnt++){ ///o(t)
            //unordered_map<char,int>temp;
            vector<int>temp(26,0);  
            for(int i=0;i<26;i++){  ///o(1)
                char ch = i + 'a'; ///0 -> a , 1 -> b....
                int freq = mp[i];
                if(ch != 'z'){
                    temp[(ch+1) -'a'] = (temp[(ch+1)-'a']+freq)%M;
                }
                else{
                    temp['a'-'a'] = (temp['a'-'a']+freq)%M;
                    temp['b'-'a'] = (temp['b'-'a']+freq)%M;
                }
            }
            ///mp = temp;/////copy happens here
            mp = move(temp); /// move happens
        }
        int res=0;
        for(int i=0;i<26;i++){
            res = (res + mp[i])%M;
        }
        return res;
    }
};


///////////
// class Solution {
// public:
//     int M = 1e9+7;
//     int lengthAfterTransformations(string s, int t) {
//         unordered_map<char,int>mp;
//         for(char &ch : s){
//             mp[ch]++;
//         }
//         for(int cnt=0; cnt<t;cnt++){ ///o(t)
//             unordered_map<char,int>temp;
//             for(auto &it : mp){  ///o(n)
//                 char ch = it.first;
//                 int freq = it.second;
//                 if(ch != 'z'){
//                     temp[ch+1] = temp[ch+1]+freq;
//                 }
//                 else{
//                     temp['a'] = (temp['a']+freq)%M;
//                     temp['b'] = (temp['b']+freq)%M;
//                 }
//             }
//             ///mp = temp;/////copy happens here
//             mp = move(temp); /// move happens
//         }
//         int res=0;
//         for(auto &it : mp){
//             res = (res + it.second)%M;
//         }
//         return res;
//     }
// };


////t-o(n^2)
////s-o(1)
// class Solution {
// public:
//     int lengthAfterTransformations(string s, int t) {
//         string s1;
//         while(t>0){
//             for(char ch : s){
//                 if(ch == 'z'){
//                     s1 += "ab";
//                 }
//                 else{
//                     s1 += char(ch+1);
//                 }
//             }
//             s = s1;
//             s1="";
//             t--;
//         }
//         // int size = s.size();
//         // return size;
//         //////
//         return s.size();
//     }
// };