////////Count Symmetric Integers

//////////https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int cnt=0;
    
            for(int i = low; i<=high; i++){
                string st = to_string(i);
                int n = st.size();
                if(n %2 != 0 ) continue;
                int left =0;
                int right =n-1;
                int sum1=0,sum2=0;
                for(int j=0;j<n/2;j++){
                    sum1 += st[left]-'0';
                    sum2 += st[right]-'0';
                    left++;
                    right--;
                }
                //////////////other approach//////////
                // int half = n/2;
                // int sum1=0,sum2=0;
                // for(int j=0;j<half;j++){
                //     sum1 += st[j]-'0';
                //     sum2 += st[half+j]-'0';
                // }
                ////////////////////
                if (sum1 == sum2) cnt++;
            }
            return cnt;
        }
    };