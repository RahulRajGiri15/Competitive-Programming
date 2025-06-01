////////Push Dominoes

/////https://leetcode.com/problems/push-dominoes/description/?envType=daily-question&envId=Invalid%20Date


class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
            vector<int>leftclosestR(n);
            vector<int>rightclosestL(n);
            ////for moving left to right to find leftclosestR
            for(int i=0;i<n;i++){
                if(dominoes[i] == 'R'){
                    leftclosestR[i] =i;
                }
                else if(dominoes[i] == '.'){
                    leftclosestR[i] = i>0 ? leftclosestR[i-1]:-1;
                }
                else if(dominoes[i]=='L'){
                    leftclosestR[i] = -1;
                }
                //////or
                // else {
                //     leftclosestR[i] = -1;
                // }
            }
            ////for moving left to right to find leftclosestR
            for(int i=n-1;i>=0;i--){
                if(dominoes[i] == 'L'){
                    rightclosestL[i] =i;
                }
                else if(dominoes[i] == '.'){
                    rightclosestL[i] = i<n-1 ?rightclosestL[i+1]:-1;
                }
    
                else if(dominoes[i]=='R'){
                    rightclosestL[i] = -1;
                }
                /////or 
                // else{
                //     rightclosestL[i] = -1;
                // }
            }
            string result(n,' '); ///create a string of length of n having char ' '
            for(int i=0;i<n;i++){
                int distleftR  = abs(i -leftclosestR[i]);
                int distrightL = abs(i - rightclosestL[i]);
    
                
                if(leftclosestR[i] == rightclosestL[i]){
                    result[i] = '.';
                }
                else if(leftclosestR[i] == -1){
                    result[i] = 'L';
                }
                else if(rightclosestL[i] == -1){
                    result[i] ='R';
                }
                else if(distleftR == distrightL){
                    result[i] = '.';
                }
                else{
                    result[i] =(distleftR > distrightL)?'L':'R';
                }
                // else if(distleftR > distrightL){
                //     result[i] = 'L';
                // }
                // else{
                //     result[i] = 'R';
                // }
                // else if(distrightL > distleftR){
                //     result[i] == 'R';
                // }
            }
            return result;
        }
    };