class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mm;    // char to index

        while(i <= j) {
            while(j < s.size() && mm.size() <= k) {
                mm[s[j]] = j;
                if(mm.size() <= k) {
                    res = max(res, j - i + 1);
                }
                j++;
            }
            if(mm[s[i]] == i) mm.erase(s[i]);
            i++;
        }
        return res;
    }
};


// 无额外存储空间
