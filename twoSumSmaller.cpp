int twoSumSmaller(vector<int> nums, int k) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i < size-1; i++) {
        int begin = i+1;
        int end = size-1;
        while(begin <= end) {
            int mid = begin + (end - begin) / 2;
            if(nums[mid] >= k - nums[i]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        res += (end - i);
    }
    return res;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    cout << twoSumSmaller(nums, 12) << endl;
}
