// User function Template for C#

class Solution {
    public bool checkYear(int n) {
        // Your code here
        //bool leapyear = true;
        
        /////////////////////////
        if(n % 400 == 0){
            return true;
        }
        
        else if(n % 4 == 0){
            if(n % 100 != 0){
                return true;
            }
        }
        
        return false;
    }
}