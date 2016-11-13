// 找到一个array of integers的equalibrium point。Equalibruim的定义是左右数字的和各相等
// return index
int findEqualibruimPoint(vector<int> nums) {
    int size = (int)nums.size();
    vector<int> postSum(size, 0);

    for(int i = size-2; i >= 0; i--) {
        postSum[i] = postSum[i+1] + nums[i+1];
    }

    int curSum = 0;

    for(int i = 1; i < size; i++) {
        curSum += nums[i-1];
        if(curSum == postSum[i]) return i;
    }
    return -1;
}


int main() {
    vector<int> nums = {1,2,4,8,9,2,24};
    cout << findEqualibruimPoint(nums) << endl;
}
