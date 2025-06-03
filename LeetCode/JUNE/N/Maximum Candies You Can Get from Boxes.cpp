/////Maximum Candies You Can Get from Boxes

//////https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/?envType=daily-question&envId=2025-06-03

class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies,vector<vector<int>>& keys,
    vector<vector<int>>& containBoxes,unordered_set<int>&visited,unordered_set<int>&foundBoxes){
        if(visited.count(box)){
            return 0;
        }
        if(status[box]==0){
            foundBoxes.insert(box);
            return 0;
        }
        
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiesCollected = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;
        for(int &box : initalBoxes){
            candiesCollected += dfs(box,status,candies,keys,containedBoxes,visited,foundBoxes);
        }
        return candiesCollected;
    }
};