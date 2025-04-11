// class Solution {
// public:

/////////////////FE-- FaithExpetation approach///////
//     vector<string> letterCombinations(string digits) {
//         vector<string> codes = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//         if(digits.size()== 0){
//             return {};
//         }
//         if(digits.size() == 1){
//             vector<string>bres;
//             string sm = codes[digits[0]-'0'-2];
//             for(char c1 : sm){
//                 bres.push_back(string(1,c1));
//             }
//             return bres;
//         }
//         char ch = digits[0];
//         string ros = digits.substr(1);
//         vector<string> res = letterCombinations(ros);
//         vector<string> mres ;
//         string chcodes = codes[ch - '0' - 2];
//         for(string str: res){
//             for(char chh : chcodes){
//                 mres.push_back(chh+str);
//             }
//         }
//         return mres;
//     }
// };

/////////////////////level order approach///////////

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> codes = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            if(digits.size()== 0){
                return {};
            }
            vector<string>asf={""};
            for(char digit : digits){
                string cdo = codes[digit-'0'-2];
                vector<string>nextlevel;
                for(string comb : asf){
                    for(char ch : cdo){
                        nextlevel.push_back(comb+ch);
                    }
                }
                asf = nextlevel;
            }
            return asf;
        }
    };
     
    
    