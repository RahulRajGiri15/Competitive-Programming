////////Find Minimum Time to Reach Last Room II

//////https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/?envType=daily-question&envId=2025-05-08


class Solution {
    public:
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        //{t, {i, j}}
        typedef pair<int, pair<int, int>> P;
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int m = moveTime.size();
            int n = moveTime[0].size();
    
            vector<vector<int>> result(m, vector<int>(n, INT_MAX));
            priority_queue<P, vector<P>, greater<P>> pq; //all cells will be inserted in it (m*n)
    
            result[0][0] = 0;
            pq.push({0, {0, 0}});
            //S.C : O(m*n)
            while(!pq.empty()) { //O(m*n * log(m*n))
                int currTime = pq.top().first;
                auto cell     = pq.top().second;
                int i = cell.first;
                int j = cell.second;
    
                pq.pop();
                if(i == m-1 && j == n-1) {
                    return currTime;
                }
    
                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
    
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                        int moveCost = (i_ + j_) % 2 == 0 ? 2 : 1;
                        int wait     = max(moveTime[i_][j_] - currTime, 0);
                        int arrTime  = currTime + wait + moveCost;
    
                        if(result[i_][j_] > arrTime) {
                            result[i_][j_] = arrTime;
                            pq.push({arrTime, {i_, j_}});
                        }
                        
                    }
                }
            }
    
            return -1;
    
        }
    };