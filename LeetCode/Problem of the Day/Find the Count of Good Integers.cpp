////////Find the Count of Good Integers


////////https://leetcode.com/problems/find-the-count-of-good-integers/description/?envType=daily-question&envId=2025-04-12


// class Solution {
// public:
//     bool isPalindrome(string str) {
//     int start = 0;
//     int end = str.length() - 1;

//     while (start < end) {
//         if (str[start] != str[end])
//             return false;
//         start++;
//         end--;
//     }
//     return true;
//     }
//     bool isplandromperm(string st,string asf,int k){
//         vector<string>permu;
//         if(st.size()==0) {
//             permu.push_pack(asf);
//             return;
//         }
        
//         for(int i=0;i<st.size();i++){
//             char ch = st[i];
//             string sleft = st.substr(0,i);
//             string sright = st.substr(i+1);
//             string roq = sleft+sright;
//             isplandromperm(roq,asf+ch,k);
//         }
//         for(strig str : permu){
//             if(isPalindrome(str)==true){
//                 int val = str-'0';
//                 if(val % k== 0){
//                     return true;
//                 }
//             }
//             return false;
//         }
//     }
//     long long countGoodIntegers(int n, int k) {
//         long long count=0;
//         string start="1",end="9";
//         for(int i=1;i<n;i++){
//             start =start +"0";
//             end = end+"9";
//         }
//         int s = start-'0';
//         int e = end-'0';
//         for(int i=s;i<=e;i++){
//             if(isplandromperm(tostring(i)," ",k) == true){
//                 count++;
//             }
//         }
//         return count;
//     }
// };

///////////////////////
// #include <iostream>
// #include <string>
// #include <set>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     bool isPalindrome(const string &str) {
//         int start = 0;
//         int end = str.length() - 1;

//         while (start < end) {
//             if (str[start] != str[end])
//                 return false;
//             start++;
//             end--;
//         }
//         return true;
//     }

//     bool isKPalindromicPermutation(string s, int k) {
//         sort(s.begin(), s.end());
//         set<string> seen;

//         do {
//             if (s[0] == '0') continue; // skip leading zeros
//             if (seen.count(s)) continue; // skip duplicates
//             seen.insert(s);

//             if (isPalindrome(s)) {
//                 int val = stoi(s);
//                 if (val % k == 0)
//                     return true;
//             }
//         } while (next_permutation(s.begin(), s.end()));

//         return false;
//     }

//     long long countGoodIntegers(int n, int k) {
//         long long count = 0;
//         int start = pow(10, n - 1);
//         int end = pow(10, n) - 1;

//         if (n == 1) start = 1; // to handle n = 1

//         for (int i = start; i <= end; i++) {
//             string num = to_string(i);
//             if (isKPalindromicPermutation(num, k)) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };
////////////////////

class Solution {
    #define ll long long
    ll k_palindromes = 0;
    unordered_set<ll> done;
    vector<ll> fact;

    void precomputeFactorial(int& n){
        fact[0] = 1;
        fact[1] = 1;
        for(ll i=2;i<=10;++i)
            fact[i] = i*fact[i-1];
    }
    ll countAllPermutations(vector<ll>& freq,int n){
        ll count = fact[n];
        for(int i=0;i<=9;++i)
            count /= fact[freq[i]];
        return count;
    }
    ll allArrangements(string number,int& n){
        sort(number.begin(),number.end());
        if(done.count(stoll(number)))//If already included then skip
            return 0;
        
        done.insert(stoll(number));
        //Find frequency of each digit
        vector<ll> freq(10);
        for(char& c: number)
            freq[c-'0']++;
        
        ll total_permutations = countAllPermutations(freq,n);
        ll invalid_permutations = 0;
        if(freq[0]>0){
            freq[0]--;
            invalid_permutations = countAllPermutations(freq,n-1);
        }
        return  total_permutations - invalid_permutations;
    }

    bool isKPalindrome(string& number,int& n,int& k){
        return (stoll(number)%k==0);
    }
    void generatePalindromes(int pos,int& n,string& number,int& k){
        if(pos>=(n+1)/2){
            if(isKPalindrome(number,n,k))
                k_palindromes += allArrangements(number,n);
            return;
        }

        char start = pos==0? '1':'0';
        while(start<='9'){
            number[pos]=start;
            number[n-pos-1]=start;
            generatePalindromes(pos+1,n,number,k);
            start++;
        }
        number[pos]=' ';
    }
public:
    long long countGoodIntegers(int n, int k) {
        fact = vector<ll>(11);
        precomputeFactorial(n);
        string number(n,' ');
        generatePalindromes(0,n,number,k);
        return k_palindromes;
    }
};