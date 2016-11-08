// assume nums[-1] = nums[n] = INT_MAX + 1
int localMinimum(vector<int>& nums) {
    int size = nums.size();
    int begin = 0, end = size - 1;
    if(nums[0] < nums[1]) return nums[0];
    if(nums[size-1] < nums[size-2]) return nums[size-1];
    while(begin <= end) {
        int mid = begin + (end - begin) / 2;
        if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) return nums[mid];
        else if(nums[mid] > nums[mid+1]) {
            begin = mid+1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2,2,3,1,1};
    cout << localMinimum(nums) << endl;
}
