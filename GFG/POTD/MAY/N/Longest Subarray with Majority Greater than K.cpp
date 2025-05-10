//////Longest Subarray with Majority Greater than K


////https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // CodeGenius
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefixsum=0,maxlen=0;
        for(int i=0;i<arr.size();i++){
            prefixsum+=(arr[i]>k)?1:-1;
            if(prefixsum>0) maxlen=i+1;
            
            if(mp.count(prefixsum-1)){
                maxlen=max(maxlen,i-mp[prefixsum-1]);
            }
            
            if(!mp.count(prefixsum)) mp[prefixsum]=i;
        }
        return maxlen;
    }
};