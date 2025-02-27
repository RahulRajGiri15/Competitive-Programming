//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        ///most optimal solution- using BS ans formuls
        int n=mat.size();
        int m=mat[0].size();/////total num of columns
        int row =0 ,col=m-1;
        while(row<n && col>=0){
            if(mat[row][col] == x) return true;
            else if(mat[row][col] < x) row++;
            else col--;
        }
        return false;
    }
};

//////method 2 -- logic is correct using binary search --- but showing some error
    //     int n =mat.size();
    //     if(n==0) return false;
    //     int m = mat[0].size();
    //     if(m==0) return false;
    //     int low=0 ,high=(n*m)-1;
    //     while(low <= high){
    //         int mid= low + (high-low)/2;
    //         int row = mid/m;
    //         int col = mid%m;
    //         if(mat[row][col] == x) return true;
    //         else if(mat[row][col]< x) low=mid+1;
    //         else high = mid-1;
    //     }
    //     return false;
    // }};
    
    ////OR
//      bool BS(vector<int>& arr, int tar){
//         int low =0 ,high=arr.size()-1;
//         while(low<=high){
//             int mid= low + (high-low)/2;
//             if(arr[mid]==tar) return true;
//             else if(arr[mid]< tar) low = mid+1;
//             else high =mid-1;
//         }
//         return false;
//     }
//     bool matSearch(vector<vector<int>> &mat, int x) {

//         int n =mat.size();
//         if(n==0) return false;
//         int m = mat[0].size();
//         if(m==0) return false;
    
//     for(int i =0;i<n;i++){
//         if(mat[i][0]<=x && mat[i][m-1]>=x){
//             if(BS(mat[i],x)){
//                 return true;
//             }
//         }
//     }
//     return false;
//     }
    
// };
        
   
//////Brute force method
// bool matSearch(vector<vector<int>> &mat, int x) {
//     int n =mat.size();
//         if(n==0) return false;
//     int m = mat[0].size();
//         if(m==0) return false;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(mat[i][j]==x) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// };


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends