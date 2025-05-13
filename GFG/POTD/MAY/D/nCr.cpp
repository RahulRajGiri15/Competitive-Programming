///////nCr


/////////https://www.geeksforgeeks.org/problems/ncr1019/1

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(r > n) return 0;
        long long ans =1;
        for(int i =1;i<=r;i++){
            ans = ans* ((n-r)+i)/i;
        }
        return (int) ans;
    }
};


//////////////////////

// class Solution {
//   public:
    
//     int fact(int num){
//         if(num == 0) return 1;
//         int f = 1;
//         for(int i =1;i<=num;i++){
//             f = f*i;
//         }
//         return f;
//     }
//     int nCr(int n, int r) {
//         // code here
//         if(r > n) return 0;
//         int  ans = fact(n)/(fact(n-r)*fact(r));
//         return ans;
//     }
// };