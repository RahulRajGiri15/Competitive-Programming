/////////////Rotate by 90 degree

//////////Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        /////int m = mat[0].size(); no need as n*n matrix is given
        ///for transpose of a matrix
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j] , mat[j][i]);
            }
        }
        /// reverseing each column
        // int top=0,bottom=n-1;
        // while(top<bottom){
        //     swap(mat[top],mat[bottom]);
        //     top++;
        //     bottom--;
        // }
        ///////OR
        for(int j=0;j<n;j++){
            int top =0 , bottom = n-1;
            while(top<bottom){
                swap(mat[top][j] ,mat[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends