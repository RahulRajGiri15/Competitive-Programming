///////////////K-th element of two Arrays

//////////https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/k-th-element-of-two-sorted-array1317

class Solution {
    public:
      int kthElement(vector<int>& a, vector<int>& b, int k) {
          ///brute force
          // vector<int> temp;
          // int n1 = a.size();
          // int n2 = b.size();
          // int i=0;
          // while(i<n1){
          //     temp.push_back(a[i]);
          //     i++;
          // }
          // i =0;
          // while(i<n2){
          //     temp.push_back(b[i++]);
          // }
          // sort(temp.begin(),temp.end());
          // return temp[k-1];
          
          /////optimal solution
          int n1 = a.size();
          int n2 = b.size();
          if(n1>n2) return kthElement(b,a,k);  ///as we need a to be smaller
          int low = max(0,k-n2);
          int high = min(n1 , k);
          int left = k;
          int n = n1+n2;
          while(low<=high){
              int mid1 = (low+high) /2;
              int mid2 = left - mid1;
              int l1 = INT_MIN , l2 =INT_MIN;
              int r1 = INT_MAX , r2 =INT_MAX;
              if(mid1< n1) r1=a[mid1];
              if(mid2< n2) r2=b[mid2];
              if(mid1-1 >=0) l1 =a[mid1-1];
              if(mid2-1 >=0) l2 =b[mid2-1];
              if(l1 <= r2 && l2 <= r1){ 
                  return max(l1,l2);
              }
              else if(l1 > r2) high = mid1 -1;
              else low = mid1+1;
          }
          
      return 0;    
          
      }
  };