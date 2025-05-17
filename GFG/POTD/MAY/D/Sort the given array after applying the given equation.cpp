/////////Sort the given array after applying the given equation


//////////https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1

class Solution {
  public:
    
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int>ans;
        int n = arr.size();
        for(int x : arr){
            ans.push_back(A*(x*x)+B*x+C);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
