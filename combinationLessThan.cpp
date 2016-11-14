// 给你一个数字的list，然后给一个target，求所有由list里面数字组合成的小于target的数，数字可以重复使用
// 比如list是{3,7,8}，target是8700，然后3, 8, 7 ... 333, 888, ... , 8377 等等都算
void helper(vector<int>& nums, vector<int>& res, int target, int sol) {
    if(sol > target) return;
    if(sol != 0 && sol < target) {
        res.push_back(sol);
    }

    for(int i = 0; i < nums.size(); i++) {
        sol = sol * 10 + nums[i];
        helper(nums, res, target, sol);
        sol = (sol - nums[i]) / 10;
    }
}

vector<int> combinationLessThan(vector<int> nums, int target) {
    vector<int> res;
    int sol;
    helper(nums, res, target, sol);
    return res;
}


int main() {
    vector<int> nums = {3,7,8};
    combinationLessThan(nums, 12);
}
