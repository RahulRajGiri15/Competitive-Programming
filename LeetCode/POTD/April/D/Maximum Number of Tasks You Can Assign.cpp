//////////Maximum Number of Tasks You Can Assign

////https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/?envType=daily-question&envId=2025-05-01

////t-o(mlogm+nlogn+logm*logm*mlogm)
////s-o(n)


class Solution {
    public:
        bool check(vector<int>&tasks,vector<int>&workers,int pills,int strength,int mid){
            int pillsUsed =0;
            multiset<int> st(begin(workers),begin(workers)+mid);
            for(int i= mid-1;i>=0;i--){///o(m)
                int reqrd = tasks[i];
                auto it = prev(st.end());
                if(*it >= reqrd){
                    st.erase(it);///logm
                }
                else if(pillsUsed >= pills){
                    return false;
                }
                else{
                    ///find the weakest worker which can do the strongest task using pill
                    auto weakestWorker = st.lower_bound(reqrd - strength);
                    if(weakestWorker == st.end()){
                        return false;
                    }
                    st.erase(weakestWorker);
                    pillsUsed++;
                }
            }
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            int m = tasks.size();
            int n = workers.size();
    
            int l = 0;
            int r = min(m,n);
            sort(tasks.begin(),tasks.end());///////asending 
            sort(workers.begin(),workers.end(), greater<int>()); //desending order
            int result = 0;
            while(l<=r){///log m
                int mid = l + (r-l)/2;
                if(check(tasks,workers,pills,strength,mid)){
                    result = mid;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            return result;
        }
    };