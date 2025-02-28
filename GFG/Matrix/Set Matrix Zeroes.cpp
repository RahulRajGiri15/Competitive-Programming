////////Set Matrix Zeroes

/////////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/set-matrix-zeroes

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        ///method 1 -- optimal solution 
        int n =mat.size();
        int m =mat[0].size();
        int col0 = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0; ///mark the ith col
                    if(j != 0)  ///mark the jth col
                        mat[0][j] =0;
                    else
                        col0=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j] != 0){
                    /// cehck for row or col
                    if(mat[i][0]==0||mat[0][j]==0){
                        mat[i][j]=0;
                    }
                }
            }
        }
        if(mat[0][0]==0){
            for(int j=0;j<m;j++) mat[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<n;i++) mat[i][0]=0;
        }
    }
};

////////method 2 -- try better and brute force


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends