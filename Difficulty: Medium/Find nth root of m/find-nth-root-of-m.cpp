class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        for(int i=0;i<=m;i++){
            if(pow(i,n) == m){
                return i;
            }
        }
        return -1;
    }
};