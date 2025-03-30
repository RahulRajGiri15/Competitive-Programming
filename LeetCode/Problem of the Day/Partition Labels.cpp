////////Partition Labels

////////https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> lastIndex(26, 0); // Store the last occurrence of each character
            
            // Step 1: Fill last occurrence of each character
            for (int i = 0; i < s.size(); i++) {
                lastIndex[s[i] - 'a'] = i;
            }
    
            vector<int> partitions;
            int start = 0, end = 0;
    
            // Step 2: Iterate and find partitions
            for (int i = 0; i < s.size(); i++) {
                end = max(end, lastIndex[s[i] - 'a']); // Extend partition end
    
                // If current index reaches partition end, create a partition
                if (i == end) {
                    partitions.push_back(end - start + 1);
                    start = i + 1; // Move start to next character
                }
            }
    
            return partitions;
        }
    };
    