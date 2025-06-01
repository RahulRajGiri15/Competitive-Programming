//////Three Consecutive Odds

//////https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11

//////o(n)
/////o(1)
// class Solution {
// public:
//     bool threeConsecutiveOdds(vector<int>& arr) {
//         if(arr.size() <3) return false;
//         for(int i=0;i<arr.size()-2;i++){
//             if(arr[i]%2 !=0){
//                 if(arr[i+1]%2!=0 && arr[i+2] %2 !=0){
//                 return true;
//             }
//             }
//         }
//         return false;
//     }
// };

/////////////
////t-o(n)
////s-o(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddcnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0){
                oddcnt+=1;
            }
            else{
                oddcnt=0;
            }
            if(oddcnt >= 3) return true;
        }
        return false;
    }
};