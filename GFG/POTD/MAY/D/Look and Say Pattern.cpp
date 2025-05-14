////////Look and Say Pattern


/////////https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if(n==1){ return "1";}
        string res="";
        string say = countAndSay(n-1);
        for(int i=0;i<say.size();i++){
            char ch = say[i];
            int cnt =1;
            while(i<say.size()-1 && say[i]==say[i+1]){
                cnt++;
                i++;
            }
            res = res + to_string(cnt) + string(1,ch);
        }
        return res;
    }
};