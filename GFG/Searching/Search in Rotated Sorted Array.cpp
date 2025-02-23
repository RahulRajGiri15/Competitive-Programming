/////////Search in Rotated Sorted Array
/////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/search-in-a-rotated-array4618

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        //////brute force approcah --- O(N)
    //     int loc =-1;
    //     for (int i =0 ;i<arr.size();i++){
    //         if(arr[i]==key){ 
    //             loc = i; 
    //             break ;
    //         }
    //     }
    //     return loc;
    // }
    
    ///////////Method 2 
    ///////Using binary search concepts --as here sorted word is uesd
   ///// bsearch -- O(logn)
    int low=0, high=arr.size()-1;
    while(low <= high){
        int mid= (low+high) /2 ;
        if(arr[mid] == key)  return mid;
        ///if left half is sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<=key && key<=arr[mid]){
                high = mid-1;  /// ELIMINATE RIGHT HALF
            }
            else low = mid+1; ///// RIGHT half
    
        }
        else{      ///////////right half is sorted
            if(arr[mid]<=key && key<=arr[high]){ 
                low= mid +1;  // elimainate left half
            }
            else high = mid -1 ;                      //   not in right half
        }
    }
    return -1;
    }
    
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends