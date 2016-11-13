// 给一个String[] of integer和int k(subset的大小), 比如[9,15,3,14] 和 3, return一个subset，
// 使得subset里面的最大值减最小值是所有subset里面最小的。所以这个例子返回[9,14,15], subset里面的数字不用按照input里的顺序。
vector<int> minimumDiffInSubset(vector<int> nums, int k) {
    int size = nums.size();
    vector<int> res;
    sort(nums.begin(), nums.end());
    int minDiff = INT_MAX;
    int beginIndex = 0;
    for(int i = 0; i < size - k + 1; i++) {
        if(minDiff > nums[i + k - 1] - nums[i]) {
            minDiff = nums[i + k - 1] - nums[i];
            beginIndex = i;
        }
    }

    while(k--) {
        res.push_back(nums[beginIndex++]);
    }
    return res;
}


int main() {
    vector<int> nums = {9, 15, 3, 14, 15,13};
    minimumDiffInSubset(nums, 4);
}
