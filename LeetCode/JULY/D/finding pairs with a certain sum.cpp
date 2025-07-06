//////https://leetcode.com/problems/finding-pairs-with-a-certain-sum/?envType=daily-question&envId=2025-07-06


class FindSumPairs {
public:
    vector<int>vec1;
    vector<int>vec2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1; //o(m)
        vec2 = nums2; //o(n)
        for(int &i : vec2){
            mp[i]++;
        }
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--;
        vec2[index] += val;
        mp[vec2[index]]++;

    }
    
    int count(int tot) {
        int c =0;
        for(int &x : vec1){
            c += mp[tot - x];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */