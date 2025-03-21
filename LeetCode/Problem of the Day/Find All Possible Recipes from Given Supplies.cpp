////////Find All Possible Recipes from Given Supplies

////https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string,vector<string>> adj;
            unordered_map<string,int> indegree;//For topological sort using Kahn's algo
    
            unordered_set<string> supply(supplies.begin(),supplies.end());
            for(int i=0;i<recipes.size();++i){
                indegree[recipes[i]] = 0;//Initialize indegree to 0
                for(string& ingredient: ingredients[i]){
                    if(supply.count(ingredient)==0){
                        //Current ingredient must be a recipe
                        adj[ingredient].push_back(recipes[i]);
                        indegree[recipes[i]]++;
                    }
                }
            }
            //Push all the start points of topological sort
            queue<string> q;
            for(auto& [recipe,indeg]: indegree)
                if(indeg==0)
                    q.push(recipe);
            
            //Apply Kahn's algo
            vector<string> res;
            while(!q.empty()){
                string curr_recipe = q.front();
                q.pop();
                res.push_back(curr_recipe);
    
                for(string& next_recipe: adj[curr_recipe]){
                    indegree[next_recipe]--;
                    if(indegree[next_recipe]==0)
                        q.push(next_recipe);
                }
            }
            return res;
        }
    };