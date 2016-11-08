int nonadjacentMaxSum(vector<int> arr) {
    int size = (int)arr.size();

    vector<int> dp(size, INT_MIN);

    for(int i = 2; i < size; i++) {
        for(int j = i - 2; j >= 0; j--) {
            dp[i] = max(dp[i], arr[j] + arr[i]);
        }
    }
    return dp[size-1];
}

int nonadjacentMaxSum(vector<int> nums) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    int index1 = -1, index2 = -1, index3 = -1;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > first) {
            third = second;
            second = first;
            first = nums[i];
            index3 = index2;
            index2 = index1;
            index1 = i;
        } else if(nums[i] > second) {
            third = second;
            second = nums[i];
            index3 = index2;
            index2 = i;
        } else if(nums[i] > third) {
            third = nums[i];
            index3 = i;
        }
    }
    cout << first << endl;
    cout << second << endl;
    cout << third << endl;
    if(abs(index1 - index2) == 1) {
        if(abs(index1 - index3) == 1) {
            return second + third;
        } else {
            return first + third;
        }
    } else {
        return first + second;
    }
}

int main() {
    vector<int> arr = {-1,2,4,2,6,-8,9,3,7,7};
    cout << nonadjacentMaxSum(arr) << endl;
}
