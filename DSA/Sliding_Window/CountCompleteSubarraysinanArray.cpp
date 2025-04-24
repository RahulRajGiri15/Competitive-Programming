/////////Count Complete Subarrays in an Array

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int,int>mp;
            int n = nums.size();
            for(int ni : nums){
                mp[ni]++;
            }
            int ucnt = mp.size();
            int cnt=0;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    unordered_map<int ,int>ansmp;
                    for(int k=i;k<=j;k++){
                        ansmp[nums[k]]++;
                    }
                    if(ansmp.size() == ucnt) cnt++; 
                    ansmp.clear();
                }
            }
            return cnt;
        }
    };

int main(){
    Solution obj;
    int n1;
    cin>>n1;
    vector<int> nums;
    for(int i =0;i<n1;i++){
        int x;
        cin>>x;
        nums.push_back(x);
        //cin>>nums[i];
    }
    ////////or
    // vector<int> nums(n1);
    // for(int i =0;i<n1;i++){
        
    //     cin>>nums[i];
    // }
    ////////
    int count = obj.countCompleteSubarrays(nums);
    cout<<count;
    return 0;
}


//////////////////////////////////////////////////////////
///////////////optimized -=-- sliding window///
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_set<int>st(nums.begin(),nums.end());
            int cnt = st.size();
            int left=0;
            int right=0;
            int result=0;
            int n = nums.size();
            unordered_map<int,int>mp;
            while(right<n){
                mp[nums[right]]++;
                while(mp.size()==cnt){
                    result += n-right;
                    
                    mp[nums[left]]--;
                    if(mp[nums[left]] == 0){
                        mp.erase(nums[left]);
                    }
                    left++;
                }
                right++;
            }
            return result;
        }
    };
    
    
    //////////// Sliding Window////
    // class Solution {
    // public:
    //     int countCompleteSubarrays(vector<int>& nums) {
    //         unordered_map<int,int>mp;
    //         int n = nums.size();
    //         for(int ni : nums){
    //             mp[ni]++;
    //         }
    //         int ucnt = mp.size();
    //         int cnt=0;
    //         int left =0,right=0;
    //         while(left<n){
    //             right =left;
    //             unordered_map<int,int>mp;
    //             while(right<n){
    //                 mp[nums[right]]++;
    //                 if(mp.size() == ucnt){
    //                     cnt += n-right;
    //                     break;
    //                 }
    //                 right++;
    //             }
    //             mp.clear();
    //             left++;
    //         }
    //         return cnt;
    //     }
    // };
    
    /////////////Hashing /// Iteration//////
    // class Solution {
    // public:
    //     int countCompleteSubarrays(vector<int>& nums) {
    //         unordered_map<int,int>mp;
    //         int n = nums.size();
    //         for(int ni : nums){
    //             mp[ni]++;
    //         }
    //         int ucnt = mp.size();
    //         int cnt=0;
    //         for(int i=0;i<n;i++){
    //             for(int j=i;j<n;j++){
    //                 unordered_map<int ,int>ansmp;
    //                 for(int k=i;k<=j;k++){
    //                     ansmp[nums[k]]++;
    //                 }
    //                 if(ansmp.size() == ucnt) cnt++; 
    //                 ansmp.clear();
    //             }
    //         }
    //         return cnt;
    //     }
    // };