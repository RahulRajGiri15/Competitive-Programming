////////Number of Substrings Containing All Three Characters

///////https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2025-03-11

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int lastseen[3] = {-1,-1,-1};
            int count = 0;
            int n=s.size();
            for(int i=0;i<n;i++){
                lastseen[s[i]-'a']= i; // Update the last seen index for the character
                //// Ensure all characters have been seen at least once
                if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1 ){
                    count =count + (1+ min({lastseen[0],lastseen[1],lastseen[2]}));
                }
            }
            return count;
    
            ///////write brtue and better approach
        }
    };