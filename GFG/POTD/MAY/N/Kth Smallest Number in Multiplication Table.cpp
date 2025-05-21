//////////Kth Smallest Number in Multiplication Table


//////////https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1

class Solution {
  public:
    int count(int mid, int m, int n) {
        int cnt = 0;
        for (int i=1; i<=m; i++) {
            cnt += min(mid/i, n);
        } return cnt;
    }
    int kthSmallest(int m, int n, int k) {
        // code here
        int start = 1, end = m*n, ans=-1;
        while (start <= end) {
            int mid = start+(end-start)/2;
            int cnt = count(mid, m, n);
            if (cnt >= k) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } return ans;
    }
};