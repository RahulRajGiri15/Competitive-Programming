//////// Candy

/////https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2025-06-02

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n; //Each person given one candy
        
        int i=1;
        while(i < n){
            
            if(ratings[i] == ratings[i-1]) {
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            
            //Note that we added candies coming from left to Peak and comgin from right to Peak
            //But, we need to consider only max from both of them for the Peak.
            //So, remove the min candy from Peak.
            candy -= min(peak, valley);
        }
        
        return candy;
    }
};
