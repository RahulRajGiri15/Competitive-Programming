/////////////Allocate Minimum Pages

///////// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/allocate-minimum-number-of-pages0937

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countStudent(vector<int>&arr ,int pages){
        int students =1; 
        long long pagesstudent =0;
        for(int i =0; i< arr.size(); i++){
            if(pagesstudent+arr[i] <= pages){
                pagesstudent +=arr[i];
            }
            else{
                students++;
                pagesstudent = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1;
        int low = *max_element(arr.begin(),arr.end()); ///for max element
        int high = accumulate(arr.begin(),arr.end(),0); ////for total sum 
        //using Binary search
        while(low <= high){
            int mid=(low+high)/2;
            int students =countStudent(arr,mid);
            if(students > k) {
                low=mid+1;
            }
            else{ 
                high = mid-1;
            }
        }
        return low;
        
        ///////////using linear search --- time limit exceeds --- brute force 
    //     int result =-1;
    //     for(int pages = low; pages<=high; pages++){
    //         int student =countStudent(arr , pages);
    //         if(student <= k ){
    //             result = pages;
    //             break;
    //         }
    //     }
    //     return result;
        
     }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends