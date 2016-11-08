int threeSumSmaller(vector<int>& nums, int target) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i < size - 2; i++) {
        int j = i + 1;
        int k = size - 1;
        while(j < k) {
            if(nums[i] + nums[j] + nums[k] >= target) {
                k--;
            } else {
                res += (k - j);
                j++;
            }
        }
    }
    return res;
}
