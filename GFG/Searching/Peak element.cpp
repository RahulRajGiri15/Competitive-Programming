//////////////Peak element
///////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/peak-element


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int n =arr.size();
        // Handle single element 
        if(n==1) return 0;
        ///for fist and last element 
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        // for middle element 
        
        //////for time complexity -- O(n)
        // for(int i =1 ;i <n-1;i++){
        //     if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
        //         return i;
        //     }
        // }
        // return -1;
        
        ///// using binary search concept -- o(log n)
        int low =1, high=arr.size()-2;
        while(low<=high) {
            int mid = (low+high) / 2;
            if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if (arr[mid] > arr[mid-1]) low = mid+1;
            else high = mid-1;
            // or 
            // else {
            //      if(arr[mid]> arr[mid+1]) high = mid-1;
            //      else low =mid+1;
            // }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends