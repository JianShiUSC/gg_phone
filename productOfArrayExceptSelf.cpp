class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> preProduct(size, 1);
        vector<int> postProduct(size, 1);
        vector<int> res(size, 1);

        for(int i = 1; i < size; i++) {
            preProduct[i] = nums[i-1] * preProduct[i-1];
        }

        for(int i = size - 2; i >= 0; i--) {
            postProduct[i] = nums[i + 1] * postProduct[i + 1];
        }

        for(int i = 0; i < size; i++) {
            res[i] = preProduct[i] * postProduct[i];
        }
        return res;
    }
};
