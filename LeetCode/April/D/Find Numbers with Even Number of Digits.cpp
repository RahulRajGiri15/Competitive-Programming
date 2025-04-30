///////Find Numbers with Even Number of Digits

////////https://leetcode.com/problems/find-numbers-with-even-number-of-digits/?envType=daily-question&envId=2025-04-30

////t-o(n)
////s-o(1)
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int cnt=0;
            for(int no :nums){
                if((no >=10 && no <=99)||
                    (no >=1000 && no <=9999)||
                    (no ==100000)){
                        cnt++;
                    }
            }
            return cnt;
        }
    };
    
    ///////////////
    ////t-o(n)
    ////s-o(1)
    // class Solution {
    // public:
    //     int findNumbers(vector<int>& nums) {
    //         int cnt=0;
    //         for(int no :nums){
    //             if(to_string(no).size() %2 == 0){
    //                 cnt++;
    //             }
    //         }
    //         return cnt;
    //     }
    // };