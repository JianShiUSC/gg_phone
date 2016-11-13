// 给个int array，找它subarray（中间indexes连续的那种）里满足 min(array)*2 > max(array)的那些，return最长的subarray（的长度）。
// O(n^2), O(1)
int longestSubarray(vector<int> nums) {
    int size = nums.size();
    int maxLen = 0;

    for(int i = 0; i < size; i++) {
        int minNum = nums[i];
        int maxNum = nums[i];
        for(int j = i; j < size; j++) {
            minNum = min(minNum, nums[j]);
            maxNum = max(maxNum, nums[j]);
            if(minNum * 2 <= maxNum) break;
            else maxLen = max(maxLen, j-i+1);
        }
    }
    return maxLen;
}

// O(nlogn), O(k)
int longestSubarray(vector<int> nums) {
    int maxLen = 0;
    int beginIndex = 0;
    int size = (int)nums.size();
    multiset<int> ss;

    for(int i = 0; i < size; i++) {
        ss.insert(nums[i]);
        int minValue = *ss.begin();
        int maxValue = *ss.rbegin();

        if(minValue*2 > maxValue) {
            maxLen = max(maxLen, (int)ss.size());
        } else {
            ss.erase(nums[beginIndex++]);
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {6};
    cout << longestSubarray(nums) << endl;
}
