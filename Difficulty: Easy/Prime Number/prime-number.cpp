class Solution {
  public:
    bool isPrime(int n) {
        
        /// code here
        // if(n == 1) return false;
        // if(n == 2) return true;
        // bool isprime = true;
        // for(int i=2;i<n;i++){
        //     if(n%i == 0){
        //         isprime = false;
        //         break;
        //     }
        // }
        // return isprime;
        
        ////////////////////
        
        if(n == 1) return false;
        if(n == 2) return true;
        bool isprime = true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0){
                isprime = false;
                break;
            }
        }
        return isprime;
    }
};
