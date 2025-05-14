//////////Total Characters in String After Transformations II


///////////https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/?envType=daily-question&envId=2025-05-14



class Solution {
public:
    const int M = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    // Multiply two 26x26 matrices
    Matrix multiply(Matrix& A, Matrix& B) {
        Matrix C(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
                }
            }
        }
        return C;
    }

    // Raise matrix A to power t
    Matrix matrixPower(Matrix A, long long t) {
        Matrix res(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) res[i][i] = 1; // identity matrix

        while (t > 0) {
            if (t % 2 == 1) res = multiply(res, A);
            A = multiply(A, A);
            t /= 2;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        // Build the transformation matrix
        Matrix T(26, vector<long long>(26, 0));
        for (int j = 0; j < 26; ++j) {
            for (int k = 1; k <= nums[j]; ++k) {
                int i = (j + k) % 26;
                T[i][j] = (T[i][j] + 1) % M;
            }
        }

        // Raise transformation matrix to the power t
        Matrix T_pow = matrixPower(T, t);

        // Multiply matrix with the frequency vector
        long long res = 0;
        for (int i = 0; i < 26; ++i) {
            long long sum = 0;
            for (int j = 0; j < 26; ++j) {
                sum = (sum + T_pow[i][j] * freq[j]) % M;
            }
            res = (res + sum) % M;
        }

        return res;
    }
};


//////////////////////

// class Solution {
// public:
//     int M = 1e9+7;
//     int lengthAfterTransformations(string s, int t, vector<int>& nums) {
//         vector<long long>mp(26,0);
//         for(char &ch : s){
//             mp[ch-'a']++;
//         }
//           while(t>0){
//             vector<long long>temp(26,0);
//             for(int i=0;i<26;i++){
//                 long long freq = mp[i];
//                 if(freq == 0) continue;
//                 int cnt = nums[i];
//                 for(int j=1;j<=cnt;j++){
//                     int idx = (i+j) %26;
//                     temp[idx] = (temp[idx]+freq)%M;
//                 }
//             }
//             mp = temp;
//             t--;
//           }
//           long long  res=0;
//           for(int i=0;i<26;i++){
//             res =(res+ mp[i])%M;
//           }
//           return res;
//     }
// };

















////////////////////////unordered_map
// class Solution {
// public:
//     int M = 1e9+7;
//     int lengthAfterTransformations(string s, int t, vector<int>& nums) {
//         unordered_map<char,int>mp;
//         for(char &ch : s){
//             mp[ch]++;
//         }
//           while(t>0){
//             unordered_map<char ,int>temp;
//             for(int i=0;i<26;i++){
//                 char ch = i+'a';
//                 int freq = mp[i];
//                 int cnt = nums[s[i]]

//             }
//           }
//     }
// };


////////////

// class Solution {
// public:
//     int M = 1e9+7;
//     int lengthAfterTransformations(string s, int t, vector<int>& nums) {
//         int n = s.size();
//         while(t>0){
//             string temp="";
//             for(int i=0;i<n;i++){
//                 int cnt = nums[s[i]-'a'];
//                 for(int j=1;j<=cnt;j++){
//                     if(s[i] != 'z'){
//                         temp += char(s[i]+j);
//                     }
//                     else{
//                         temp += 'ab';
//                     }
//                 }
//             }
//             s=temp;
//             temp="";
//             t--;
//         }
//         return s.size();
//     }
// };