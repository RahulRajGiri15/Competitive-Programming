///////////Search in a row-wise sorted matrix

/////////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-row-wise-sorted-matrix

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        for(int i=0;i<n;i++){
            if(binary_search(mat[i].begin(),mat[i].end() ,x)) return true; 
        }
        return false;
        
        ////method 2 -Wrong - as here matrix is sorted row wise only not col wise 
        // int m = mat[0].size();
        // int row=0, col=m-1;
        // while(row<n && col>=0){
        //     if(mat[row][col]==x) return true;
        //     else if(mat[row][col]< x) row++;
        //     else col--;
        // }
        // return false;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends