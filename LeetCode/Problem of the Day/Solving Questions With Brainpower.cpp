/////////////Solving Questions With Brainpower

//////https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01

class Solution {
    #define ll long long

    ll findMaxPoints(vector<vector<int>>& questions,int pos,vector<ll>& mem){
        if(pos >= questions.size())
            return 0;
        if(mem[pos]!=-1)
            return mem[pos];
        
        ll exclude = findMaxPoints(questions,pos+1,mem);
        ll include = questions[pos][0] + findMaxPoints(questions,pos+questions[pos][1]+1,mem);
        return mem[pos] = max(exclude,include);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> mem(n,-1);
        return findMaxPoints(questions,0,mem);
    }
};