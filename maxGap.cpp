// 给一个unsorted array, for all a[i] <= a[j], i < j 找出 j - i 最大的值。。。O(N) time O(N) Space
int findMaximumGap(vector<int> nums) {
    if(nums.empty()) return 0;
    int size = (int)nums.size();
    vector<int> smallestSoFar(size, 0);
    smallestSoFar[0] = nums[0];

    for(int i = 1; i < nums.size(); i++) {
//        smallestSoFar[i] = (nums[i] < smallestSoFar[i-1] ? nums[i] : smallestSoFar[i-1]);
        smallestSoFar[i] = min(nums[i], smallestSoFar[i-1]);
    }

    /*
     存完后从数组最右往左遍历 记录结果max, 如果a[right] > small[right - max - 1] 更新max = max + 1
     如果发现a[right] <= smallest[right - max - 1] 说明，a[right] 比这之前的都小，就right--继续遍历。。。 直到right <= max。。。。
     */

    int max = 0;
    for(int j = size - 1; j > max; j--) {
        while(nums[j] >= smallestSoFar[j-max-1]) {
            ++max;
        }
    }
    return max;
}

int main() {
    vector<int> nums = {6, 2, 3, 4, 3, 5, 6};
    cout << findMaximumGap(nums) << endl;
}
