///////////Count Largest Group

///////https://leetcode.com/problems/count-largest-group/?envType=daily-question&envId=2025-04-23

class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int,int>mp;
            for(int i=1;i<=n;i++){
                int sum=0;
                int temp=i;
                while(temp>0){
                    sum += temp%10;
                    temp=temp/10;
                }
                mp[sum]++;
            }
            ///finding largest group size
            int maxsize=0;
            for(auto &it :mp){
                maxsize = max(maxsize, it.second);
            }
            int cnt=0;
            for(auto &it : mp){
                if(it.second == maxsize){
                    cnt++;
                }
            }
            return cnt;
        }
    };