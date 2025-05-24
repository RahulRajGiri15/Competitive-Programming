/////////Sum of all substrings of a number


/////////https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

class Solution {
  public:
    int sumSubstrings(string &s) {
        //CodeGenius
        long long int sum=0;
        long long int mf=1;
        for(int i=s.size()-1;i>=0;i--){
            sum+=(s[i]-'0')*(i+1)*mf;
            mf=mf*10+1;
        }
        return sum;
    }
};