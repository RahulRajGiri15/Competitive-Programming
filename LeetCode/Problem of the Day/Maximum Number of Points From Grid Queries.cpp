/////////Maximum Number of Points From Grid Queries

/////////https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/?envType=daily-question&envId=2025-03-28

class Solution {
    #define pii pair<int,int>
    #define pip pair<int,pii>

    bool isValid(int& x,int& y,int& m,int& n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        set<int> sorted_queries(queries.begin(),queries.end());//We need to only solve for unique query

        unordered_map<int,int> query_count;
        priority_queue<pip,vector<pip>,greater<pip>> minheap;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        //Apply BFS for each query incrementally (since, a larger query will always cover the cells of a smaller query)
        minheap.push(make_pair(grid[0][0],make_pair(0,0)));
        visited[0][0]=true;
        vector<int> dir = {-1,0,1,0,-1};

        int count = 0;
        for(int query: sorted_queries){
            while(!minheap.empty()){
                pip curr = minheap.top();
                minheap.pop();

                int val=curr.first;
                int x=curr.second.first;
                int y=curr.second.second;
                if(val >= query){
                    minheap.push(curr);
                    break;
                }
                count++;    //Count current node
                
                for(int i=0;i<4;++i){
                    int newX = x + dir[i];
                    int newY = y + dir[i+1];
                    if(isValid(newX,newY,m,n) and !visited[newX][newY]){
                        visited[newX][newY] = true;
                        minheap.push(make_pair(grid[newX][newY],make_pair(newX,newY)));
                    }
                }
            }
            query_count[query] = count;
        }

        //Build the answer
        vector<int> res;
        for(int query: queries)
            res.push_back(query_count[query]);
        return res;
    }
};