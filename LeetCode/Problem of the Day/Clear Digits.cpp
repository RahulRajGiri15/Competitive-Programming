////// Count digits ///
// https://leetcode.com/problems/clear-digits/description/

class Solution {
    public:
        string clearDigits(string s) {
            string ns;
            for(char c: s){
                if(c>='0' and c<='9') ns.pop_back();
                else                 ns.push_back(c);
                // if(c>='a' and c<='z') ns.push_back(c);
                // else                 ns.pop_back();
            }
            return ns;
            
        }
    };