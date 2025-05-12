//////Finding 3-Digit Even Numbers

////https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12

/////t-o(n^3)
/////s-o(n)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n =digits.size();
        vector<int>ans(10,0);
        vector<int>res;
        for(int i=0;i<n;i++){
            ans[digits[i]]++;
        }
        for(int i=1;i<=9;i++){
            if(ans[i] == 0)continue;
            ans[i]--;
            for(int j=0;j<=9;j++){
                if(ans[j] == 0)continue;
                ans[j]--;
                for(int k=0;k<=8;k +=2){
                    if(ans[k] == 0) continue;
                    ans[k]--;
                    int num = i*100+j*10+k;
                    res.push_back(num);
                    ans[k]++;
                }
                ans[j]++;
            }
            ans[i]++;
        }
        return res;
    } 
};





//////////////////////////////
//////t-o(n^3 + slogs)
/////s-o(2s)--s-unique elements
// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         unordered_set<int>st;
//         int n =digits.size();
//         for(int i =0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 for(int k=0;k<n;k++){
//                     if(i == j || j == k || k == i){
//                         continue;
//                     }
//                     int num = digits[i]*100+ digits[j]*10+digits[k];
//                     if(num >=100 && num %2 == 0){
//                         st.insert(num);
//                     }
//                 }
//             }
//         }
//         vector<int>ans(begin(st),end(st));
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };