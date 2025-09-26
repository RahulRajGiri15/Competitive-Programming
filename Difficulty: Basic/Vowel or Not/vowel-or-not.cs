// User function Template for C#

class Solution {
    // Complete this function
    // Function to check if the character is a vowel or not.
   
    public string isVowel(char c) {
        // Your code here
        c = char.ToLower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ){
            return "YES";
        }
        return "NO";
    }
}