class Solution {
    public bool isPalindrome(string s) {
        // code here
        int n = s.Length;
        //string r ;
        int l = 0;
        int r = n-1;
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
