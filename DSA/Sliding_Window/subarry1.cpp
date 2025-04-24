///print all subarrays of a string
//////iteration method///

// #include<iostream>
// using namespace std;

// int main(){
//     string s = "abcde";
//     int n= s.size();
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             for(int k=i;k<=j;k++){
//                 cout<<s[k]<<"";
//             }
//             cout<<endl;
//         }
//     }
// }

///////sliding window method///

#include<iostream>
using namespace std;

int main(){
    string s = "abcde";
    int n= s.size();
    int left = 0;
    int right = 0;
    while(left<n){
        right = left;
        string temp ="";
        while(right<n){
            temp += s[right];
            cout<<temp<<" ";
            right++;
        }
        cout<<endl;
        left++;
        }
    }

/////sliding window

// #include<iostream>
// using namespace std;

// int main(){
//     string s = "abcde";
//     int n= s.size();
//     int left = 0;
//     int right = 0;
//     for(int start=0;start<n;start++){
//         for(int end=start;end<n;end++){
//             cout<<
//         }
//     }