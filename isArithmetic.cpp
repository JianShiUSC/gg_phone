/*
数组1：{7，4，2，2}
数组2：{{1，2}，{0，3}, {2，3}}代表数组1的index
输出就是判断结果： Y, N, Y
*/
vector<bool> isArithmetic(vector<int> nums, vector<pair<int, int>> index) {
    int size = (int)nums.size();
    vector<bool> res;
    vector<int> startPos(size, 0);

    int preDiff = 0;

    for(int i = 1; i < nums.size(); i++) {
        int curDiff = nums[i] - nums[i - 1];
        startPos[i] = (curDiff == preDiff) ? startPos[i-1] : (i - 1);
        preDiff = curDiff;
    }

    for(auto range : index) {
        res.push_back(startPos[range.second] <= range.first);
    }
    return res;
}


int main() {
    vector<int> nums = {7,4,2,2,1,2,3};
    vector<pair<int, int>> index = {{1,2},{0,3},{2,3},{4,6},{3,5}};
    isArithmetic(nums, index);
}
